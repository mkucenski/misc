if [ $(uname) == "FreeBSD" ]; then
	EDITOR=vi;   	export EDITOR
	PAGER=more;  	export PAGER

	# set ENV to a file invoked each time sh is started for interactive use.
	ENV=$HOME/.shrc; export ENV

	# if [ -x /usr/games/fortune ] ; then /usr/games/fortune freebsd-tips ; fi
	eval $(ssh-agent -s) > /dev/null
fi

if [ $(uname) == "Darwin" ]; then
	alias ofh="$HOME/Scripts/macOS/open-finder-here.sh"
	export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
	export PATH="$HOME/Development/opt/bin:$HOME/Development/opt/sbin:$PATH"
	export PATH="$HOME/Scripts:$HOME/Scripts/macOS:$PATH"
	# export PATH="$HOME/Library/Python/2.7/bin:$PATH"
	export PATH="/Applications/VMware OVF Tool:$PATH"
	# export PATH="/opt/local/Library/Frameworks/Python.framework/Versions/2.7/bin/:$PATH"
	export PATH="$HOME/Python/bin:$PATH"

	# Increase maximum number of open files (needed for libewf/tsk)
	ulimit -n 2048

	# Python...
	export PYTHONPATH="/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages"
	export PYTHONPATH="$HOME/Library/Python/2.7/site-packages:$PYTHONPATH"

	# Java
	export JAVA_HOME=$(/usr/libexec/java_home)
fi

# If not running interactively, don't do anything else
[ -z "$PS1" ] && return

echo; fortune -a "$HOME/Development/MyGitHub/misc/fortunes/"; echo

alias ll="ls -l"
alias llh="ls -lh"


