# .bashrc is executed for interactive, but non-login shells (i.e. subsequent shells after the first login)
#

HISTFILESIZE=400000000
HISTSIZE=10000
HISTTIMEFORMAT="%Y%m%d %H:%M:%S "
PROMPT_COMMAND="history -a"

shopt -s histappend

export PATH="$HOME/Scripts:$PATH"
export PATH="$HOME/Development/opt/bin:$HOME/Development/opt/sbin:$PATH"

UNAME="$(uname)"

if [ "$UNAME" == "FreeBSD" ]; then

	EDITOR=vi;   	export EDITOR
	PAGER=more;  	export PAGER

	# set ENV to a file invoked each time sh is started for interactive use.
	ENV=$HOME/.shrc; export ENV

	# if [ -x /usr/games/fortune ] ; then /usr/games/fortune freebsd-tips ; fi
	eval $(ssh-agent -s) > /dev/null

elif [ "$UNAME" == "Darwin" ]; then

	export PATH="$HOME/Scripts/macOS:$PATH"

	export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
	export PATH="/Applications/VMware OVF Tool:$PATH"
	export PATH="$HOME/Python/bin:$PATH"

	# Increase maximum number of open files (needed for libewf/tsk)
	ulimit -n 2048

	# Python...
	export PYTHONPATH="/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages"
	export PYTHONPATH="$HOME/Library/Python/2.7/site-packages:$PYTHONPATH"

	# Java
	export JAVA_HOME=$(/usr/libexec/java_home)
else
	echo "Unknown Operating System!"
fi

echo; fortune -a "$HOME/Development/MyGitHub/misc/fortunes/"; echo

alias ll="ls -l"
alias llh="ls -lh"

