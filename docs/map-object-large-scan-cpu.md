# Large map-object scan CPU composition

`tools/map_object_large_scan_cpu.py:LargeScan` composes the existing eligibility/cache/initial scan bodies with the complete large creation CPU model. All130 instruction bytes already have exact matching sources; this strengthens the model with zero duplicate credit.

The final capture passed1,536 complete original calls,512each C0DDE3/C0DDBE/C0DD8B. Inputs explicitly set ED-negative large mode,215 nonboss identities,three allocated actor slots,48 cache entries,counts0..48,both palette pages and the global early-stop flag. Eligibility uses real viewport/event bounds, then real large-object palette/identity/stat/graphics/program initialization. Initial scanning restores the original saved count/context and scans only the native three slots.

Every call compares full randomized128KiB WRAM outside129caller-stack bytes, full CPU A/X/Y/C/N/Z/V/M/X,S/D/DB,static peripherals and ordered audio. Native D0/DB7E/M8/X16/binary is explicit. No hooks bypass instructions. Dependencies and report/coverage fingerprints are checked before integration.

The complete boss-containing loader, boss fall-through C20000, arbitrary context, interrupt timing and live rendering remain open. Returned graphics and animation data are read from the supplied ROM without storing payloads. The earlier ordinary-domain proof remains available separately and in catalogue history.
