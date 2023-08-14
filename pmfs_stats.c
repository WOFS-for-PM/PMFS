#include "pmfs.h"

const char *Timingstring[TIMING_NUM] = 
{
	"create",
	"lookup",
	"unlink",
	"readdir",
	"xip_read",
	"xip_write",
	"xip_write_fast",
	"internal_write",
	"memcpy_read",
	"memcpy_write",
	"alloc_blocks",
	"new_trans",
	"add_logentry",
	"commit_trans",
	"mmap_fault",
	"fsync",
	"free_tree",
	"evict_inode",
	"recovery",
	"find_block",
	"read_meta_block",
	"write_meta_block",
	"read_pi_i_blk_type",
	"read_pi_height",
	"read_pi_i_blocks",
	"read_pi_i_flags",
	"read_pi_attr",
	"read_pi",
	"check_pi_free",
	"write_pi_time_and_size",
	"write_pi_time",
	"write_pi_size",
	"write_pi_root",
	"write_pi_height",
	"write_pi_i_blocks",
	"write_pi_links",
	"write_pi",
	"pmfs_clean_journal",
	"new_trans_alloc_tail",
	"read_trans_tail",
	"read_trans_head",
	"read_trans_base",
	"read_trans_genid",
	"read_trans_type",
	"write_trans_genid",
	"write_log_entry",
	"read_journal_head",
	"write_journal_head",
	"read_journal_tail",
	"read_genid",
	"read_dentry",
	"write_dentry",
	"add_truncate_item",
	"write_data",
	"read_data",
};

unsigned long long Timingstats[TIMING_NUM];
u64 Countstats[TIMING_NUM];
u64 IOstats[STATS_NUM];
DEFINE_PER_CPU(u64[STATS_NUM], IOstats_percpu);

atomic64_t fsync_pages = ATOMIC_INIT(0);

void pmfs_get_IO_stats(void)
{
	int i;
	int cpu;

	for (i = 0; i < STATS_NUM; i++) {
		IOstats[i] = 0;
		for_each_possible_cpu(cpu)
			IOstats[i] += per_cpu(IOstats_percpu[i], cpu);
	}
}

void pmfs_print_meta_stats(void)
{
	pmfs_get_IO_stats();
	u64 cow_write_time = Timingstats[xip_write_t];
	u64 meta_time = Timingstats[read_metablock_t] + Timingstats[write_metablock_t] 
		+ Timingstats[read_pi_i_blk_type_t] + Timingstats[read_pi_height_t]
		+ Timingstats[read_pi_i_blocks_t] + Timingstats[read_pi_attr_t]
		+ Timingstats[read_pi_t] + Timingstats[check_pi_free_t]
		+ Timingstats[write_pi_time_and_size_t] 
		+ Timingstats[write_pi_time_t] + Timingstats[write_pi_size_t] 
		+ Timingstats[write_pi_root_t] + Timingstats[write_pi_height_t] 
		+ Timingstats[write_pi_i_blocks_t] + Timingstats[write_pi_link_t]
		+ Timingstats[write_pi_t] + Timingstats[write_trans_tail_t]
		+ Timingstats[read_trans_tail_t] + Timingstats[read_trans_head_t]
		+ Timingstats[read_trans_base_t] + Timingstats[read_trans_genid_t]
		+ Timingstats[read_trans_type_t] + Timingstats[write_trans_genid_t]
		+ Timingstats[write_log_entry_t] + Timingstats[read_journal_head_t]
		+ Timingstats[write_journal_head_t] + Timingstats[read_journal_tail_t]
		+ Timingstats[read_genid] + Timingstats[read_de_t]
		+ Timingstats[write_de_t] + Timingstats[add_truncate_item_t];
	u64 meta_times = Countstats[read_metablock_t] + Countstats[write_metablock_t] 
		+ Countstats[read_pi_i_blk_type_t] + Countstats[read_pi_height_t]
		+ Countstats[read_pi_i_blocks_t] + Countstats[read_pi_attr_t]
		+ Countstats[read_pi_t] + Countstats[check_pi_free_t]
		+ Countstats[write_pi_time_and_size_t] 
		+ Countstats[write_pi_time_t] + Countstats[write_pi_size_t] 
		+ Countstats[write_pi_root_t] + Countstats[write_pi_height_t] 
		+ Countstats[write_pi_i_blocks_t] + Countstats[write_pi_link_t]
		+ Countstats[write_pi_t] + Countstats[write_trans_tail_t]
		+ Countstats[read_trans_tail_t] + Countstats[read_trans_head_t]
		+ Countstats[read_trans_base_t] + Countstats[read_trans_genid_t]
		+ Countstats[read_trans_type_t] + Countstats[write_trans_genid_t]
		+ Countstats[write_log_entry_t] + Countstats[read_journal_head_t]
		+ Countstats[write_journal_head_t] + Countstats[read_journal_tail_t]
		+ Countstats[read_genid] + Countstats[read_de_t]
		+ Countstats[write_de_t] + Countstats[add_truncate_item_t];
	u64 memcpy_time = Timingstats[memcpy_w_t];

	pr_info("=========== PMFS meta_trace stats ============\n");
	pr_info("meta_read: %llu\n", IOstats[meta_read]);
	pr_info("meta_write: %llu\n", IOstats[meta_write]);
	pr_info("data_read: %llu\n", IOstats[data_read]);
	pr_info("data_write: %llu\n", IOstats[data_write]);
	pr_info("meta_time: %llu\n", meta_time); 		
	pr_info("meta_times: %llu\n", meta_times);		
	pr_info("data_write_time: %llu\n", Timingstats[memcpy_w_t]);
	pr_info("data_read_time: %llu\n", Timingstats[memcpy_r_t]);
	pr_info("COW_time: %llu\n", cow_write_time);
	pr_info("read_time: %llu\n", Timingstats[read_data_t]);
}





void pmfs_print_timing_stats(void)
{
	int i;

	printk("======== PMFS kernel timing stats ========\n");
	for (i = 0; i < TIMING_NUM; i++) {
		if (measure_timing || Timingstats[i]) {
			printk("%s: count %llu, timing %llu, average %llu\n",
				Timingstring[i],
				Countstats[i],
				Timingstats[i],
				Countstats[i] ?
				Timingstats[i] / Countstats[i] : 0);
		} else {
			printk("%s: count %llu\n",
				Timingstring[i],
				Countstats[i]);
		}
	}

	pmfs_print_meta_stats();
}

void pmfs_clear_stats(void)
{
	int i;

	printk("======== Clear PMFS kernel timing stats ========\n");
	for (i = 0; i < TIMING_NUM; i++) {
		Countstats[i] = 0;
		Timingstats[i] = 0;
	}
}
