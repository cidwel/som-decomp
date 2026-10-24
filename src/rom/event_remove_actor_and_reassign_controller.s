; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-party-actors.md.
.setcpu "65816"
.smart
.a8
.i16

restore_party_hud_across_two_native_frames = $E0DB
routine_00bdbb = $BDBB

.segment "CODE"
.org $ED01
event_remove_actor_and_reassign_controller:
    rep #$30
    lda $04
    .a16
    and #$0F00
    asl
    tax
    .a16
    lda #$0080
    sta a:$E000,X
    inc $D1
    inc $D1
    sep #$20
    lda a:$E02C,X
    beq event_remove_actor_and_reassign_controller_c1ed32
    stz a:$E02C,X
    .a8
    and #$0F
    dec
    .a8
    cmp #$03
    bne event_remove_actor_and_reassign_controller_c1ed27
    .a8
    lda #$02
event_remove_actor_and_reassign_controller_c1ed27:
    sep #$10
    tax
    .a8
    lda #$00
    sta $D9,X
    jsl f:routine_00bdbb
event_remove_actor_and_reassign_controller_c1ed32:
    jmp restore_party_hud_across_two_native_frames
