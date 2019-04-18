# .bash_profile is executed for login shells
# Except macOS -- all Terminal shells are "login"

if [ -f "$HOME/.bashrc" ]; then
	source "$HOME/.bashrc"
fi

export MANPATH="/opt/local/share/man:$MANPATH"

