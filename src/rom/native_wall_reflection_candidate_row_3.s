.setcpu "65816"
.segment "CODE"
.org $4D96
.macro actor_slot_offset role
    .word role * $0200
.endmacro
native_wall_reflection_candidate_row_3:
    actor_slot_offset 1
    actor_slot_offset 2
    actor_slot_offset 0
