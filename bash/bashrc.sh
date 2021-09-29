# .bashrc is executed for interactive, but non-login shells (i.e. subsequent shells after the first login)

UNAME="$(uname)"

# ENVIRONMENT VARIABLES

HISTFILESIZE=400000000
HISTSIZE=10000
HISTTIMEFORMAT="%Y%m%d %H:%M:%S "
PROMPT_COMMAND="history -a"
shopt -s histappend

export PATH="$HOME/Scripts:$PATH"
export PATH="$HOME/Scripts/tsk:$PATH"
export PATH="$HOME/Development/opt/bin:$HOME/Development/opt/sbin:$PATH"
export MANPATH="$HOME/Development/opt/share/man:$MANPATH"

export PATH="$HOME/perl5/bin${PATH:+:${PATH}}"
export PERL5LIB="$HOME/perl5/lib/perl5${PERL5LIB:+:${PERL5LIB}}"
export PERL_LOCAL_LIB_ROOT="$HOME/perl5${PERL_LOCAL_LIB_ROOT:+:${PERL_LOCAL_LIB_ROOT}}"
export PERL_MB_OPT="--install_base \"$HOME/perl5\""
export PERL_MM_OPT="INSTALL_BASE=$HOME/perl5"

if [ "$UNAME" == "Darwin" ]; then
	export PATH="$HOME/Scripts/macOS:$PATH"
	export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
	export PATH="/Applications/VMware OVF Tool:$PATH"
	export PATH="$HOME/Python/bin:$PATH"
	export MANPATH="/opt/local/share/man:$MANPATH"

	# Python...
	export PYTHONPATH="/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages"
	export PYTHONPATH="$HOME/Library/Python/2.7/site-packages:$PYTHONPATH"

	# Java
	export JAVA_HOME=$(/usr/libexec/java_home)
else
	if [ "$UNAME" == "FreeBSD" ]; then
		EDITOR=vi;   	export EDITOR
		PAGER=less;  	export PAGER

		# set ENV to a file invoked each time sh is started for interactive use.
		ENV=$HOME/.shrc; export ENV
	fi
fi

alias ll="ls -l"
alias llh="ls -lh"
alias cll="clear; ls -l"
alias cllh="clear; ls -lh"
alias rot13="tr 'A-Za-z' 'N-ZA-Mn-za-m'"
#alias info='pinfo'
#alias man='pinfo'

# LOCAL-HOST SPECIFIC

if [ -f "$HOME/.bashrc_local" ]; then
	source "$HOME/.bashrc_local"
fi

# EXECUTABLES

if [ "$UNAME" != "Darwin" ]; then
	eval $(ssh-agent -s) > /dev/null
	ssh-add
	ssh-add "$HOME/.ssh/mygithub_rsa_personal"
fi

echo; uname -a
if [ $(which cpufetch) ]; then echo; cpufetch 2>/dev/null | tail -n +3; fi
if [ $(which fortune) ]; then echo; fortune -a "$HOME/Development/MyGitHub/misc/fortunes/"; fi
