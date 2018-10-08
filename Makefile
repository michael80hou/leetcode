# -----------------------------------------------------------------------------
# Sub-Components
# -----------------------------------------------------------------------------

SUBCOMP_DEP1  = array
SUBCOMP_DEP2  = math
SUBCOMP_DEP3  = string
SUBCOMP_DEP4  = list
SUBCOMP_DEP5  = unclarified
SUBCOMP_DEP6  = test
OUTPUT := out


SUBCOMPONENTS = $(SUBCOMP_DEP1) $(SUBCOMP_DEP2) $(SUBCOMP_DEP3) $(SUBCOMP_DEP4) $(SUBCOMP_DEP5) $(SUBCOMP_DEP6)

# -----------------------------------------------------------------------------
# Rules
# -----------------------------------------------------------------------------

.PHONY: $(SUBCOMPONENTS)

all: $(SUBCOMPONENTS)
$(SUBCOMP_DEP1): $(SUBCOMP_DEP2)
$(SUBCOMP_DEP2): $(SUBCOMP_DEP3)
$(SUBCOMP_DEP3): $(SUBCOMP_DEP4)
$(SUBCOMP_DEP4): $(SUBCOMP_DEP5)
$(SUBCOMP_DEP5): $(SUBCOMP_DEP6)

$(SUBCOMPONENTS):
	$(MAKE) -C $@

clean:
	@rm -rf ./$(OUTPUT)/*
	
recompile:	clean all
