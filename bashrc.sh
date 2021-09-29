# .bashrc is executed for interactive, but non-login shells (i.e. subsequent shells after the first login)

HISTFILESIZE=400000000
HISTSIZE=10000
HISTTIMEFORMAT="%Y%m%d %H:%M:%S "
PROMPT_COMMAND="history -a"

shopt -s histappend

export PATH="$HOME/Scripts:$HOME/Scripts/tsk:$PATH"
export PATH="$HOME/Development/opt/bin:$HOME/Development/opt/sbin:$PATH"

export MANPATH="$HOME/Development/opt/share/man:$MANPATH"

UNAME="$(uname)"

if [ "$UNAME" == "FreeBSD" ]; then

	EDITOR=vi;   	export EDITOR
	PAGER=more;  	export PAGER

	# set ENV to a file invoked each time sh is started for interactive use.
	ENV=$HOME/.shrc; export ENV

	# if [ -x /usr/games/fortune ] ; then /usr/games/fortune freebsd-tips ; fi

	eval $(ssh-agent -s) > /dev/null

elif [ "$UNAME" == "Linux" ]; then

	eval $(ssh-agent -s) > /dev/null

elif [ "$UNAME" == "Darwin" ]; then
	export PATH="$HOME/Scripts/macOS:$PATH"
	export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
	export PATH="/Applications/VMware OVF Tool:$PATH"
	export PATH="$HOME/Python/bin:$PATH"
	export PATH="/opt/local/Library/Frameworks/Python.framework/Versions/3.6/bin:$PATH"
	export PATH="/opt/metasploit-framework/bin:$PATH"

	export MANPATH="/opt/local/share/man:$MANPATH"

	# Python...
	export PYTHONPATH="/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages"
	export PYTHONPATH="$HOME/Library/Python/2.7/site-packages:$PYTHONPATH"

	# Java
	export JAVA_HOME=$(/usr/libexec/java_home -v 1.8)
	alias bfg="java -jar $HOME/Development/GitHub/rtyley/bfg-repo-cleaner/bfg/target/bfg-1.13.1-SNAPSHOT-master-aeee9e3.jar"

	export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig

	export CPPFLAGS="-I/opt/local/include -I$HOME/Development/opt/include -I/usr/local/include"
	export LDFLAGS="-L/opt/local/lib -L$HOME/Development/opt/lib -L/usr/local/lib"
else
	echo "Unknown Operating System!"
fi

# Add .ssh/id_rsa[.private]
ssh-add -A

echo; fortune -a "$HOME/Development/MyGitHub/misc/fortunes/"; echo

alias ll="ls -l"
alias llh="ls -lh"
alias cll="clear; ls -l"
alias cllh="clear; ls -lh"
alias rot13="tr 'A-Za-z' 'N-ZA-Mn-za-m'"
alias grep="grep --color=auto"

PATH="$HOME/perl5/bin${PATH:+:${PATH}}"; export PATH;
PERL5LIB="$HOME/perl5/lib/perl5${PERL5LIB:+:${PERL5LIB}}"; export PERL5LIB;
PERL_LOCAL_LIB_ROOT="$HOME/perl5${PERL_LOCAL_LIB_ROOT:+:${PERL_LOCAL_LIB_ROOT}}"; export PERL_LOCAL_LIB_ROOT;
PERL_MB_OPT="--install_base \"$HOME/perl5\""; export PERL_MB_OPT;
PERL_MM_OPT="INSTALL_BASE=$HOME/perl5"; export PERL_MM_OPT;

if [ -e "$HOME/.bashrc" ]; then
	source "$HOME/.bashrc_local"
fi


