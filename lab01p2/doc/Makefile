PANDOC = pandoc
PANDOCFLAGS = -s -p --toc -N --mathjax --css=css/markdown.css --css=css/messages.css

DOC_MD = ../ReadMe.md

DOC_HTML = SysProg_Lab01p2.html

all: $(DOC_HTML)

$(DOC_HTML): $(DOC_MD)
	$(PANDOC) $(PANDOCFLAGS) $< -o $@

clean:
	rm -rf *.html
