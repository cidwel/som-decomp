; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6BF8
dispatch_native_menu_ring_phase_from_original_jump_table:
    sep #$30
    .a8
    lda #$01
    sta a:$180C
    sta a:$1807
    lda a:$1812
    asl
    tax
    rep #$30
    lda a:$181E
    jmp ($6C0F,X)
