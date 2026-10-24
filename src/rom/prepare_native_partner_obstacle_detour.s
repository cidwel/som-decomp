; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

reverse_native_diagonal_partner_motion_for_retry = $B929
search_native_horizontal_detour_after_vertical_motion = $B78D
search_native_vertical_detour_after_horizontal_motion = $B877

.segment "CODE"
.org $B729
prepare_native_partner_obstacle_detour:
    tyx
    stx $10
    sep #$20
    lda a:$E00B,X
    .a8
    cmp #$80
    .a8
    and #$03
    sta $04
    rep #$20
    bcs prepare_native_partner_obstacle_detour_c1b747
    .a16
    lda #$0000
    sta $0A
    .a16
    lda #$B800
    sta $0D
    bra prepare_native_partner_obstacle_detour_c1b751
prepare_native_partner_obstacle_detour_c1b747:
    .a16
    lda #$4000
    sta $0A
    .a16
    lda #$BC00
    sta $0D
prepare_native_partner_obstacle_detour_c1b751:
    lda a:$E006,X
    sta $06
    beq prepare_native_partner_obstacle_detour_c1b780
    lda a:$E002,X
    lsr
    lsr
    lsr
    lsr
    sta $08
    lda a:$E004,X
    .a16
    and #$0FF0
    asl
    asl
    asl
    ora $08
    sta $08
    sep #$20
    .a8
    lda #$7F
    sta $0C
    sta $0F
    lda $06
    beq prepare_native_partner_obstacle_detour_c1b785
    lda $07
    beq prepare_native_partner_obstacle_detour_c1b781
    bne prepare_native_partner_obstacle_detour_c1b789
prepare_native_partner_obstacle_detour_c1b780:
    rtl
prepare_native_partner_obstacle_detour_c1b781:
    jsr search_native_vertical_detour_after_horizontal_motion
    rtl
prepare_native_partner_obstacle_detour_c1b785:
    jsr search_native_horizontal_detour_after_vertical_motion
    rtl
prepare_native_partner_obstacle_detour_c1b789:
    jsr reverse_native_diagonal_partner_motion_for_retry
    rtl
