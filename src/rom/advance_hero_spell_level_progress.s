; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

read_actor_element_spell_level = $4E6E
routine_c03989 = $C03989
routine_c05b75 = $C05B75

object_actor_kind = $E1FB
hero_spell_progress_cap = $CFFC
object_cast_element_index = $E177
object_element_spell_progress = $E1D8
object_packed_spell_levels = $E1C4

.segment "CODE"
.org $4DCD
advance_hero_spell_level_progress:
    lda a:object_actor_kind,Y
    bmi advance_hero_spell_level_progress_d04dd3
    rtl
advance_hero_spell_level_progress_d04dd3:
    jsr read_actor_element_spell_level
    lda a:hero_spell_progress_cap
    .a8
    cmp #$08
    bne advance_hero_spell_level_progress_d04dde
    inc
advance_hero_spell_level_progress_d04dde:
    sta $A6
    lda $9D
    cmp $A6
    bcc advance_hero_spell_level_progress_d04dec
    lda $9E
    sta $A8
    bra advance_hero_spell_level_progress_d04e5d
advance_hero_spell_level_progress_d04dec:
    .a8
    lda #$09
    sec
    sbc $9D
    sta $AC
    lda a:$00ED
    bmi advance_hero_spell_level_progress_d04dfa
    lsr $AC
advance_hero_spell_level_progress_d04dfa:
    lda a:object_cast_element_index,Y
    sta $CC
    ldy $CC
    lda a:object_element_spell_progress,Y
    sta $9E
    clc
    adc $AC
    sta $A8
    .a8
    cmp #$64
    bcc advance_hero_spell_level_progress_d04e5d
    .a8
    lda #$08
    cmp $9D
    bne advance_hero_spell_level_progress_d04e1c
    .a8
    lda #$63
    sta $A8
    jmp advance_hero_spell_level_progress_d04e5d
advance_hero_spell_level_progress_d04e1c:
    stz $A8
    inc $9D
    ldy $83
    lda a:object_cast_element_index,Y
    .a8
    bit #$01
    bne advance_hero_spell_level_progress_d04e39
    lsr
    sta $CC
    ldy $CC
    lda a:object_packed_spell_levels,Y
    clc
    .a8
    adc #$10
    sta a:object_packed_spell_levels,Y
    bra advance_hero_spell_level_progress_d04e45
advance_hero_spell_level_progress_d04e39:
    lsr
    sta $CC
    ldy $CC
    lda a:object_packed_spell_levels,Y
    inc
    sta a:object_packed_spell_levels,Y
advance_hero_spell_level_progress_d04e45:
    lda $A8
    pha
    phx
    phy
    ldx $83
    jsl f:routine_c05b75
    .a8
    lda #$CF
    jsl f:routine_c03989
    ply
    sty $CC
    plx
    pla
    sta $A8
advance_hero_spell_level_progress_d04e5d:
    ldy $83
    lda a:object_cast_element_index,Y
    sta $CC
    ldy $CC
    lda $A8
    sta a:object_element_spell_progress,Y
    ldy $83
    rtl
