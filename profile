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
	export PATH="~/Development/opt/bin:~/Development/opt/sbin:$PATH"
	export PATH="~/Scripts:~/Scripts/macOS:$PATH"
	export PATH="~/Library/Python/2.7/bin:$PATH"

	# Increase maximum number of open files (needed for libewf/tsk)
	ulimit -n 2048

	export JAVA_HOME=$(/usr/libexec/java_home)
fi

echo; fortune -a "$HOME/Development/MyGitHub/misc/fortunes/"; echo

