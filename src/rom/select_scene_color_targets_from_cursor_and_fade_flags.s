; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9D78
select_scene_color_targets_from_cursor_and_fade_flags:
    sep #$30
    ldx $7B
    .i8
    cpx #$00
    beq select_scene_color_targets_from_cursor_and_fade_flags_c09d8f
    lda $5F
    .a8
    and #$04
    .a8
    cmp #$04
    txa
    bcc select_scene_color_targets_from_cursor_and_fade_flags_c09d8b
    .a8
    eor #$FE
select_scene_color_targets_from_cursor_and_fade_flags_c09d8b:
    bmi select_scene_color_targets_from_cursor_and_fade_flags_c09db9
    bra select_scene_color_targets_from_cursor_and_fade_flags_c09dad
select_scene_color_targets_from_cursor_and_fade_flags_c09d8f:
    sep #$30
    .i8
    ldx #$05
    lda $F2
    bpl select_scene_color_targets_from_cursor_and_fade_flags_c09d99
    .i8
    ldx #$17
select_scene_color_targets_from_cursor_and_fade_flags_c09d99:
    .i8
    ldy #$05
select_scene_color_targets_from_cursor_and_fade_flags_c09d9b:
    lda a:$9DC5,X
    sta a:$0A4C,Y
    bit $F2
    bpl select_scene_color_targets_from_cursor_and_fade_flags_c09da8
    sta a:$0A46,Y
select_scene_color_targets_from_cursor_and_fade_flags_c09da8:
    dex
    dey
    bpl select_scene_color_targets_from_cursor_and_fade_flags_c09d9b
    rts
select_scene_color_targets_from_cursor_and_fade_flags_c09dad:
    sep #$30
    .i8
    ldx #$0B
    lda $F2
    bpl select_scene_color_targets_from_cursor_and_fade_flags_c09d99
    .i8
    ldx #$1D
    bra select_scene_color_targets_from_cursor_and_fade_flags_c09d99
select_scene_color_targets_from_cursor_and_fade_flags_c09db9:
    sep #$30
    .i8
    ldx #$11
    lda $F2
    bpl select_scene_color_targets_from_cursor_and_fade_flags_c09d99
    .i8
    ldx #$23
    bra select_scene_color_targets_from_cursor_and_fade_flags_c09d99
