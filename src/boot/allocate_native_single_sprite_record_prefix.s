; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-single-sprite-allocate.md.
.setcpu "65816"
.smart
.a8
.i16

restore_native_single_sprite_allocation_frame = $B72B
routine_00b6ff = $B6FF
routine_7eb612 = $B612

.segment "CODE"
.org $B6D0
allocate_native_single_sprite_record_prefix:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta $02
    lda a:$02CE
    beq routine_00b6ff
    lda $02
    jsr routine_7eb612
    .i16
    cpx #$0000
    beq restore_native_single_sprite_allocation_frame
    .a8
    lda #$01
    sta a:$0008,X
    lda $02
    sta a:$000B,X
    bra restore_native_single_sprite_allocation_frame
