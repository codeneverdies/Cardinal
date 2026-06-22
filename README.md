# An attempt at stopping memory acquisition via crash dumps.

This driver will remove it's self from a kernel crash dump, in an attempt to stop an attacker that wants to dump it from the crash dump.
It does this by registering a bug check callback reason routine using `KeRegisterBugCheckCallbackRoutine`, and supplying `KbCallbackRemovePages`.
While the crash dump is being written, our callback will be called. That is when we remove the pages of the kernel driver from the crash dump. 
For more information read my blog [post]() :), if you have any questions or wanna talk about it feel free to message me on twitter or discord.