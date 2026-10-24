# Complete ordinary and large nonboss map-loader CPU composition

`tools/map_object_load_cpu.py:Loader` reconstructs the complete C0DCDC wrapper through native slot preparation, cache initialization and initial ordinary/large scanning. Its32 instruction bytes already have exact matching source and receive no duplicate credit.

The final successful comparison covers every original map object list without boss ids in all four ordinary/large and fresh/restored-cache contexts, plus1024synthetic WRAM lists. Counts0..48,all215 nonboss ids,bothpalettepages,earlystop,bothincomingM widths andsavedDB00/42/7E/7F/C0 are explicit. D0/X16/binary is the native domain. Original source count, pointer and bank are captured before preparation clears their overlapping actor-region header. The wrapper restores DB and its PLB flags while preserving the actual scan accumulator/carry/overflow residues.

Full randomized128KiB WRAM outside129caller-stack bytes,allCPU/context/staticperipherals andordered audio match with no bypass hooks. Dependencies include the complete palette, identity/stats, graphics conversion,program/cache/terrain andscan models. ROM map data is read at runtime without saving payloads.

Invalidcounts49..255 remain in the native nonreturn guard, separately observed in the previous bounded32-step memory proof. This comparison covers returning nonboss loader contexts; boss-containing maps,the C20000 dispatch,arbitraryD,interrupttiming andlive rendering remain open. Total original-call counts,actual-map counts anddependency fingerprints are recorded in the report.
