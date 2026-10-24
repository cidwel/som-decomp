; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

snapshot_map_scroll_and_actor_cache = $CBEA

.segment "CODE"
.org $CBCB
snapshot_map_state_entry:
    jsr snapshot_map_scroll_and_actor_cache
    rtl
