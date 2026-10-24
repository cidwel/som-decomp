; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_native_ring_projection_and_handle_final_direction_step = $6C6D

.segment "CODE"
.org $6C47
store_native_ring_radius_then_project_rows:
    sta a:$181E
    bra prepare_native_ring_projection_and_handle_final_direction_step
