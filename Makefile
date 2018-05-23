EXE=analysisLog.pdf
SRC=analysisLog.tex
BIB=analysisLog.aux

$(EXE):$(SRC)
	xelatex $(SRC)

.PHONY.:look
look:
	evince analysisLog.pdf

.PHONY.:clean
clean:
	$(RM) analysisLog.aux analysisLog.log analysisLog.pdf analysisLog.dvi analysisLog.bbl analysisLog.blg analysisLog.toc analysisLog.out analysisLog.nav analysisLog.snm analysisLog.thm analysisLog.lot analysisLog.lof
