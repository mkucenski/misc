export PATH="$HOME/Scripts/:$PATH"
export PATH="$HOME/Development/opt/bin/:$HOME/Development/opt/sbin/:$PATH"
export PATH="$HOME/.local/bin/:$PATH"
export PATH="$HOME/.cargo/bin/:$PATH"

export MANPATH="$HOME/Development/opt/share/man/:$MANPATH"

export EDITOR="$(which vim)"

export GEM_HOME=$HOME/.gem

alias vi=vim

# OS-Specific Actions
UNAME="$(uname)"
if [[ "$UNAME" == "FreeBSD" ]]; then

	eval $(ssh-agent > /dev/null)
	#source "$HOME/.restic/env"

	#alias cat="bat"

	alias nslookup="echo 'Use [drill] to lookup'"
	alias dig="echo 'Use [drill] to lookup'"

elif [[ "$UNAME" == "Linux" ]]; then

	#alias cat="batcat"
	export PATH="/opt/fluent-bit/bin/:$PATH"
	export PATH="/opt/Bitwarden/:$PATH"

elif [[ "$UNAME" == "Darwin" ]]; then

	export PATH=/opt/local/bin:$PATH

else
fi

# Final OS-Agnostic Actions
if [[ -e $(which fortune) ]]; then echo; fortune -a "$HOME/Development/MyGitHub/misc/fortunes/"; echo; fi

if [[ -e "$ZSH_CUSTOM/zsh_private.zsh" ]]; then . "$ZSH_CUSTOM/zsh_private.zsh"; fi

# Enable Ctrl-x-e to edit command line
autoload -U edit-command-line
zle -N edit-command-line
bindkey -M vicmd v edit-command-line
