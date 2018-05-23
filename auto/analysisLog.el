(TeX-add-style-hook
 "analysisLog"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("ctexbook" "a4paper" "openany" "12pt")))
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "latex2e"
    "setup/setup"
    "chapter00/cover"
    "chapter00/preface"
    "chapter00/contents"
    "chapter01/chapter01"
    "chapter02/chapter02"
    "chapter03/chapter03"
    "chapter04/chapter04"
    "chapter05/chapter05"
    "chapter06/chapter06"
    "chapter07/chapter07"
    "chapter08/chapter08"
    "chapter09/chapter09"
    "appendix/appendix"
    "bib/analysisBib"
    "ctexbook"
    "ctexbook12")))

