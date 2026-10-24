; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-attack-palette.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_fifteen_palette_colors_from_rom = $D90D
restore_actor_cached_fifteen_palette_colors = $D8F3

.segment "CODE"
.org $CA04
prepare_or_restore_actor_attack_palette:
    bcc prepare_or_restore_actor_attack_palette_c1ca18
    .i16
    cpx #$0600
    bcs prepare_or_restore_actor_attack_palette_c1ca17
    lda a:$E100,X
    .a8
    bit #$08
    beq prepare_or_restore_actor_attack_palette_c1ca15
    jsr restore_actor_cached_fifteen_palette_colors
prepare_or_restore_actor_attack_palette_c1ca15:
    sep #$20
prepare_or_restore_actor_attack_palette_c1ca17:
    rtl
prepare_or_restore_actor_attack_palette_c1ca18:
    .a8
    lda #$57
    .i16
    cpx #$0000
    beq prepare_or_restore_actor_attack_palette_c1ca28
    .a8
    lda #$5A
    .i16
    cpx #$0200
    beq prepare_or_restore_actor_attack_palette_c1ca28
    .a8
    lda #$5D
prepare_or_restore_actor_attack_palette_c1ca28:
    sta $0C
    .a8
    lda #$CD
    pha
    .a8
    and #$03
    inc
    clc
    adc $0C
    sta a:$E102,X
    lda $0C
    sta a:$E101,X
    inc
    sta a:$E103,X
    pla
    .a8
    and #$04
    lsr
    lsr
    .a8
    ora #$88
    sta a:$E100,X
    jsr load_actor_fifteen_palette_colors_from_rom
    sep #$20
    rtl
