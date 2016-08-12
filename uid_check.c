#include <linux/module.h>
#include <linux/cred.h>

int hide_uid[100];
unsigned int hide_uid_count=0;
module_param_array(hide_uid, int, &hide_uid_count, 0644);

int check_hide_uid(void)
{
    int i;
    for (i = 0; i < hide_uid_count; i++)
    {
        if (hide_uid[i] == current_uid())
            return 1;
    }
    return 0;
}
