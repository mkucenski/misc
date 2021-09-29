# .bash_profile (this file) is executed for "login"
# shells; except macOS -- all macOS Terminal shells
# are "login"
#
# Sourcing .bashrc to make it the definitive
# location for all bash shell environments

if [ -f "$HOME/.bashrc" ]; then
	source "$HOME/.bashrc"
fi


##
# Your previous /Users/mkucenski/.bash_profile file was backed up as /Users/mkucenski/.bash_profile.macports-saved_2021-04-12_at_21:38:52
##

# MacPorts Installer addition on 2021-04-12_at_21:38:52: adding an appropriate DISPLAY variable for use with MacPorts.
export DISPLAY=:0
# Finished adapting your DISPLAY environment variable for use with MacPorts.

