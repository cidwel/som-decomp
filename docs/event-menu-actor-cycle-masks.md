# Alternate hero eligibility masks

The six bytes at C06B46 are the cyclic sequence 1,2,4,1,2,4. C06B0F tests these masks against controller binding and actor availability; C06AFA reads the next cyclic mask during fallback.

The frozen 8,192-call actor-cycle proof includes 3,072 native C06B0A calls covering all six indices and 512 binding/active/dead combinations for each index. The numeric evidence preserves the report, capture and checker hashes. This addition grants six typed data bytes and zero new instruction bytes; it reuses those original comparisons without repeating them. The complete source build independently checks every table byte.

Evidence: data/event_menu_actor_cycle_numeric.json; source: src/rom/native_menu_alternate_hero_masks.s.
