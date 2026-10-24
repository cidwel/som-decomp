.setcpu "65816"
.segment "CODE"
.org $4D7E
.macro actor_slot_offset role
    .word role * $0200
.endmacro
native_wall_reflection_candidate_row_0:
    actor_slot_offset 0
    actor_slot_offset 1
    actor_slot_offset 2
