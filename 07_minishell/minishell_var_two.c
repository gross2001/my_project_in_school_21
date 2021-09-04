#include "minishell.h"

void	writing_all_dop1(void)
{
	g_var.all_vars[12] = ft_strjoin("declare -x PATH=", getenv("PATH"));
	g_var.all_vars[13] = ft_strjoin("declare -x PWD=", getenv("PWD"));
	g_var.all_vars[14] = ft_strjoin("declare -x LANG=", getenv("LANG"));
	g_var.all_vars[15] = ft_strjoin("declare -x ITERM_PROFILE=", \
		getenv("ITERM_PROFILE"));
	g_var.all_vars[16] = ft_strjoin("declare -x XPC_FLAGS=", \
		getenv("XPC_FLAGS"));
	g_var.all_vars[17] = ft_strjoin("declare -x XPC_SERVICE_NAME=", \
		getenv("XPC_SERVICE_NAME"));
	g_var.all_vars[18] = ft_strjoin("declare -x SHLVL=", \
		getenv("SHLVL"));
	g_var.all_vars[19] = ft_strjoin("declare -x HOME=", getenv("HOME"));
	g_var.all_vars[20] = ft_strjoin("declare -x COLORFGBG=", \
		getenv("COLORFGBG"));
}

void	writing_all_dop(void)
{
	writing_all_dop1();
	g_var.all_vars[21] = ft_strjoin("declare -x LC_TERMINAL_VERSION=", \
		getenv("LC_TERMINAL_VERSION"));
	g_var.all_vars[22] = ft_strjoin("declare -x ITERM_SESSION_ID=", \
		getenv("ITERM_SESSION_ID"));
	g_var.all_vars[23] = ft_strjoin("declare -x LESS=", getenv("LESS"));
	g_var.all_vars[24] = ft_strjoin("declare -x LOGNAME=", getenv("LOGNAME"));
	g_var.all_vars[25] = ft_strjoin("declare -x LC_TERMINAL=", \
		getenv("LC_TERMINAL"));
	g_var.all_vars[26] = ft_strjoin("declare -x COLORTERM=", \
		getenv("COLORTERM"));
	g_var.all_vars[27] = ft_strjoin("declare -x _=", getenv("_"));
	g_var.all_vars[28] = NULL;
}

void	writing_all(void)
{
	g_var.all_vars = malloc(sizeof(char *) * 29);
	g_var.all_vars[0] = ft_strjoin("declare -x TERM_PROGRAM=", \
		getenv("TERM_PROGRAM"));
	g_var.all_vars[1] = ft_strjoin("declare -x TERM=", getenv("TERM"));
	g_var.all_vars[2] = ft_strjoin("declare -x SHELL=", getenv("SHELL"));
	g_var.all_vars[3] = ft_strjoin("declare -x TMPDIR=", getenv("TMPDIR"));
	g_var.all_vars[4] = ft_strjoin("declare -x TERM_PROGRAM_VERSION=", \
		getenv("TERM_PROGRAM_VERSION"));
	g_var.all_vars[5] = ft_strjoin("declare -x TERM_SESSION_ID=", \
		getenv("TERM_SESSION_ID"));
	g_var.all_vars[6] = ft_strjoin("declare -x ZSH=", getenv("ZSH"));
	g_var.all_vars[7] = ft_strjoin("declare -x USER=", getenv("USER"));
	g_var.all_vars[8] = ft_strjoin("declare -x SSH_AUTH_SOCK=", \
		getenv("SSH_AUTH_SOCK"));
	g_var.all_vars[9] = ft_strjoin("declare -x __CF_USER_TEXT_ENCODING=", \
		getenv("__CF_USER_TEXT_ENCODING"));
	g_var.all_vars[10] = ft_strjoin("declare -x PAGER=", getenv("PAGER"));
	g_var.all_vars[11] = ft_strjoin("declare -x LSCOLORS=", getenv("LSCOLORS"));
	writing_all_dop();
}

void	writing_var_dop(void)
{
	g_var.vars[12] = ft_strjoin("PATH=", getenv("PATH"));
	g_var.vars[13] = ft_strjoin("PWD=", getenv("PWD"));
	g_var.vars[14] = ft_strjoin("LANG=", getenv("LANG"));
	g_var.vars[15] = ft_strjoin("ITERM_PROFILE=", getenv("ITERM_PROFILE"));
	g_var.vars[16] = ft_strjoin("XPC_FLAGS=", getenv("XPC_FLAGS"));
	g_var.vars[17] = ft_strjoin("XPC_SERVICE_NAME=", \
		getenv("XPC_SERVICE_NAME"));
	g_var.vars[18] = ft_strjoin("SHLVL=", getenv("SHLVL"));
	g_var.vars[19] = ft_strjoin("HOME=", getenv("HOME"));
	g_var.vars[20] = ft_strjoin("COLORFGBG=", getenv("COLORFGBG"));
	g_var.vars[21] = ft_strjoin("LC_TERMINAL_VERSION=", \
		getenv("LC_TERMINAL_VERSION"));
	g_var.vars[22] = ft_strjoin("ITERM_SESSION_ID=", \
		getenv("ITERM_SESSION_ID"));
	g_var.vars[23] = ft_strjoin("LESS=", getenv("LESS"));
	g_var.vars[24] = ft_strjoin("LOGNAME=", getenv("LOGNAME"));
	g_var.vars[25] = ft_strjoin("LC_TERMINAL=", getenv("LC_TERMINAL"));
	g_var.vars[26] = ft_strjoin("COLORTERM=", getenv("COLORTERM"));
	g_var.vars[27] = ft_strjoin("_=", getenv("_"));
	g_var.vars[28] = NULL;
	writing_all();
}

void	writing_var(void)
{
	g_var.ret = 0;
	g_var.vars = malloc(sizeof(char *) * 29);
	g_var.vars[0] = ft_strjoin("TERM_PROGRAM=", getenv("TERM_PROGRAM"));
	g_var.vars[1] = ft_strjoin("TERM=", getenv("TERM"));
	g_var.vars[2] = ft_strjoin("SHELL=", getenv("SHELL"));
	g_var.vars[3] = ft_strjoin("TMPDIR=", getenv("TMPDIR"));
	g_var.vars[4] = ft_strjoin("TERM_PROGRAM_VERSION=", \
		getenv("TERM_PROGRAM_VERSION"));
	g_var.vars[5] = ft_strjoin("TERM_SESSION_ID=", getenv("TERM_SESSION_ID"));
	g_var.vars[6] = ft_strjoin("ZSH=", getenv("ZSH"));
	g_var.vars[7] = ft_strjoin("USER=", getenv("USER"));
	g_var.vars[8] = ft_strjoin("SSH_AUTH_SOCK=", getenv("SSH_AUTH_SOCK"));
	g_var.vars[9] = ft_strjoin("__CF_USER_TEXT_ENCODING=", \
		getenv("__CF_USER_TEXT_ENCODING"));
	g_var.vars[10] = ft_strjoin("PAGER=", getenv("PAGER"));
	g_var.vars[11] = ft_strjoin("LSCOLORS=", getenv("LSCOLORS"));
	writing_var_dop();
}
