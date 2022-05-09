#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xd2d6ffbd, "module_layout" },
	{ 0x9b9819be, "kmem_cache_destroy" },
	{ 0xbc6084dc, "iget_failed" },
	{ 0x3186837a, "kmalloc_caches" },
	{ 0x68fecb20, "drop_nlink" },
	{ 0x359cb5af, "make_bad_inode" },
	{ 0x25905e32, "generic_file_llseek" },
	{ 0x27864d57, "memparse" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x6e199694, "param_ops_int" },
	{ 0x754d539c, "strlen" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x365d4b6c, "vmf_insert_mixed" },
	{ 0x815b5dd4, "match_octal" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x853aab8a, "generic_fh_to_parent" },
	{ 0x1db7706b, "__copy_user_nocache" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0x7f9fcefc, "seq_puts" },
	{ 0x77e0ec50, "is_bad_inode" },
	{ 0x84f15016, "boot_cpu_data" },
	{ 0xb2db598c, "generic_file_open" },
	{ 0x159219e8, "touch_atime" },
	{ 0xc0a3d105, "find_next_bit" },
	{ 0xa5d7fad0, "seq_printf" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x44e9a829, "match_token" },
	{ 0x7da2aff3, "inc_nlink" },
	{ 0x6c067818, "init_user_ns" },
	{ 0xa6093a32, "mutex_unlock" },
	{ 0xbe6444f0, "mount_bdev" },
	{ 0x85df9b6c, "strsep" },
	{ 0x410fbadf, "generic_read_dir" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x21271fd0, "copy_user_enhanced_fast_string" },
	{ 0x2cf868f0, "kthread_create_on_node" },
	{ 0xa40ed836, "make_kgid" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0x18a8c2fd, "inode_owner_or_capable" },
	{ 0xfb578fc5, "memset" },
	{ 0x79ea0ce3, "from_kuid" },
	{ 0x524b2dcf, "current_task" },
	{ 0x9a76f11f, "__mutex_init" },
	{ 0xc5850110, "printk" },
	{ 0x911ce5e1, "kthread_stop" },
	{ 0xe1537255, "__list_del_entry_valid" },
	{ 0x4f6c705f, "d_obtain_alias" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x1edb69d6, "ktime_get_raw_ts64" },
	{ 0x1f199d24, "copy_user_generic_string" },
	{ 0xf1e046cc, "panic" },
	{ 0xfb4a3c6b, "file_remove_privs" },
	{ 0x479c3c86, "find_next_zero_bit" },
	{ 0xfac19588, "__clear_user" },
	{ 0x8480e593, "from_kgid" },
	{ 0xbd6841d4, "crc16" },
	{ 0xfb481954, "vprintk" },
	{ 0x5ad58f22, "kmem_cache_free" },
	{ 0x41aed6e7, "mutex_lock" },
	{ 0x9c41fd29, "set_nlink" },
	{ 0x440f12dd, "setattr_copy" },
	{ 0x19f2b8d7, "insert_inode_locked" },
	{ 0x4e3567f7, "match_int" },
	{ 0xdbafd02d, "up_write" },
	{ 0xfea1e2d3, "down_write" },
	{ 0x68f31cbd, "__list_add_valid" },
	{ 0x3b80edf7, "inode_init_once" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xecdcabd2, "copy_user_generic_unrolled" },
	{ 0x40740e09, "mnt_drop_write_file" },
	{ 0xc6cbbc89, "capable" },
	{ 0x6958ae23, "dax_get_by_host" },
	{ 0x5db1595f, "kmem_cache_alloc" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xeccdb68d, "make_kuid" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x1000e51, "schedule" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x6b899022, "unlock_new_inode" },
	{ 0xb8299cea, "mnt_want_write_file" },
	{ 0x384e97d8, "kill_block_super" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x200ab677, "inode_newsize_ok" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0x3efd1889, "dax_direct_access" },
	{ 0x90abd77a, "wake_up_process" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb1381ad5, "kmem_cache_alloc_trace" },
	{ 0x129fd1c0, "kmem_cache_create" },
	{ 0xc92da891, "register_filesystem" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xddb387a7, "iput" },
	{ 0x37a0cba, "kfree" },
	{ 0x5e76a6d2, "ihold" },
	{ 0x69acdf38, "memcpy" },
	{ 0x15a479d8, "__sb_end_write" },
	{ 0x859e53e7, "current_time" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x32f1de00, "d_splice_alias" },
	{ 0x4f1925fc, "__sb_start_write" },
	{ 0xf007d10f, "d_make_root" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xfe3af5db, "unregister_filesystem" },
	{ 0xdc576753, "init_special_inode" },
	{ 0x5ab03927, "new_inode" },
	{ 0x9b25e83c, "__bdev_dax_supported" },
	{ 0x90c35b1f, "noop_fsync" },
	{ 0x255cd3b3, "generic_fh_to_dentry" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0x1ec340a0, "clear_inode" },
	{ 0xcf17606a, "d_instantiate" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xac656c04, "clear_nlink" },
	{ 0x1ab9f136, "iget_locked" },
	{ 0xc31ea6c4, "setattr_prepare" },
	{ 0xdd646ce6, "generic_fillattr" },
	{ 0xf9e4c2c2, "inode_init_owner" },
	{ 0x84a7f020, "truncate_inode_pages" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "37B0E5C24B04750EA23D59F");
