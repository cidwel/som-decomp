; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-party-actors.md.
.setcpu "65816"
.smart
.a8
.i16

restore_party_hud_across_two_native_frames = $E0DB
set_actor_program_long = $C10020

.segment "CODE"
.org $ECA0
event_activate_actor_and_rebuild_party_hud:
    rep #$30
    ldy $D4
    lda $04
    .a16
    and #$0F00
    asl
    tax
    .a16
    lda #$0001
    sta a:$E000,X
    ldy $3A
    lda a:$E002,Y
    sta a:$E002,X
    lda a:$E004,Y
    sta a:$E004,X
    .a16
    lda #$0000
    sta a:$E006,X
    sta a:$E008,X
    ldy $D4
    inc $D1
    inc $D1
    sep #$20
    lda a:$E00B,Y
    sta a:$E00B,X
    lda a:$E08E,Y
    sta a:$E08E,X
    lda a:$E04C,Y
    sta a:$E04C,X
    lda a:$E010,Y
    .a8
    cmp #$02
    bcc event_activate_actor_and_rebuild_party_hud_c1eced
    .a8
    eor #$80
    bra event_activate_actor_and_rebuild_party_hud_c1ecef
event_activate_actor_and_rebuild_party_hud_c1eced:
    .a8
    eor #$01
event_activate_actor_and_rebuild_party_hud_c1ecef:
    sta a:$E010,X
    .a8
    lda #$FF
    sta a:$E030,X
    lda a:$E180,X
    jsl f:set_actor_program_long
    jmp restore_party_hud_across_two_native_frames
