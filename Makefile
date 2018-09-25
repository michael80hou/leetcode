# -----------------------------------------------------------------------------
# Sub-Components
# -----------------------------------------------------------------------------

SUBCOMP_DEP1  = array
SUBCOMP_DEP2  = math
SUBCOMP_DEP3  = string
SUBCOMP_DEP4  = unclarified
SUBCOMP_DEP5  = test


SUBCOMPONENTS = $(SUBCOMP_DEP1) $(SUBCOMP_DEP2) $(SUBCOMP_DEP3) $(SUBCOMP_DEP4) $(SUBCOMP_DEP5)

# -----------------------------------------------------------------------------
# Rules
# -----------------------------------------------------------------------------

.PHONY: $(SUBCOMPONENTS)

all: $(SUBCOMPONENTS)
$(SUBCOMP_DEP1): $(SUBCOMP_DEP2)
$(SUBCOMP_DEP2): $(SUBCOMP_DEP3)
$(SUBCOMP_DEP3): $(SUBCOMP_DEP4)
$(SUBCOMP_DEP4): $(SUBCOMP_DEP5)

$(SUBCOMPONENTS):
	$(MAKE) -C $@

clean:
	@rm -rf $(OUTPUT)/*
	
recompile:	clean all
