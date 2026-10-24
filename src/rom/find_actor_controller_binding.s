; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DF0A
find_actor_controller_binding:
    bit $D9
    bne find_actor_controller_binding_c1df19
    bit $DA
    bne find_actor_controller_binding_c1df1c
    bit $DB
    bne find_actor_controller_binding_c1df1f
    .a8
    lda #$00
    rts
find_actor_controller_binding_c1df19:
    .a8
    lda #$01
    rts
find_actor_controller_binding_c1df1c:
    .a8
    lda #$02
    rts
find_actor_controller_binding_c1df1f:
    .a8
    lda #$04
    rts
