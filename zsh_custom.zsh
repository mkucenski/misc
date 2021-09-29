export PATH="$HOME/Scripts:$PATH"
export PATH="$HOME/Development/opt/bin:$HOME/Development/opt/sbin:$PATH"

export MANPATH="$HOME/Development/opt/share/man:$MANPATH"

UNAME="$(uname)"

if [[ "$UNAME" == "FreeBSD" ]]; then

	eval $(ssh-agent > /dev/null)

elif [[ "$UNAME" == "Linux" ]]; then

	echo "Linux!"

elif [[ "$UNAME" == "Darwin" ]]; then

	export PATH=/opt/local/bin:$PATH

else
	echo "Unknown Operating System!"
fi

if [[ -e $(which fortune) ]]; then echo; fortune -a "$HOME/Development/MyGitHub/misc/fortunes/"; echo; fi

