export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
export PATH="~/Development/opt/bin:~/Development/opt/sbin:$PATH"
export PATH="~/Scripts:~/Scripts/macOS:$PATH"
export PATH="~/Library/Python/2.7/bin:$PATH"

##
# Your previous /Users/matthew.kucenski/.profile file was backed up as /Users/matthew.kucenski/.profile.macports-saved_2016-10-31_at_12:41:46
##

# MacPorts Installer addition on 2016-10-31_at_12:41:46: adding an appropriate PATH variable for use with MacPorts.
export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
# Finished adapting your PATH environment variable for use with MacPorts.

echo; fortune -a "$HOME/Development/MyGitHub/misc/fortunes/"; echo

# Increase maximum number of open files (needed for libewf/tsk)
ulimit -n 2048

