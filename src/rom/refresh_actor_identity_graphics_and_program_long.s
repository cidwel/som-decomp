; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-identity-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_map_object_identity_graphics_and_ai = $E038

.segment "CODE"
.org $E034
refresh_actor_identity_graphics_and_program_long:
    jsr refresh_map_object_identity_graphics_and_ai
    rtl
