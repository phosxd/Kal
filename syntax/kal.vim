if exists("b:current_syntax")
    finish
endif

syntax keyword kal_type num str
syntax keyword kal_todo TODO NOTE FIXME README

syntax keyword kal_keyword var del const
syntax keyword kal_keyword stdin stdout stderr
syntax keyword kal_keyword style
syntax keyword kal_keyword exit warn throw
syntax keyword kal_keyword read write
syntax keyword kal_keyword concat
syntax keyword kal_keyword list push join size unpack range reverse

syntax match kal_preproc "@.*$"
syntax match kal_shebang "#!.*$" 

syntax region kal_string start='"'  end='"'
syntax region kal_comment start=';' end=';' contains=kal_todo

highlight kal_keyword     ctermfg=cyan
highlight kal_todo        ctermfg=white    ctermbg=gray    cterm=bold
highlight kal_comment     ctermfg=gray                     cterm=italic
highlight kal_string      ctermfg=green
highlight kal_shebang     ctermfg=red                      cterm=bold
highlight kal_type        ctermfg=magenta
highlight kal_preproc     ctermfg=177                      cterm=italic
