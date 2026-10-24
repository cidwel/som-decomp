; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-palette-child.md.
.setcpu "65816"
.smart
.a8
.i16

clear_spell_status_and_mark_reciprocal_contacts = $9FBD
copy_boss_palette_with_cpu_words = $26F9
select_next_live_active_party_spell_target = $9A74
set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9D64
alternate_spell_palette_while_target_animation_active:
    ldx $87
    jsr set_eligible_spell_target_status_and_timer
    lda a:$009E,X
    bne alternate_spell_palette_while_target_animation_active_c29d75
    jsr clear_spell_status_and_mark_reciprocal_contacts
    jsr select_next_live_active_party_spell_target
    rts
alternate_spell_palette_while_target_animation_active_c29d75:
    lda a:$00B6,X
    inc
    inc
    sta $95
    lda a:$00BC,X
    inc
    cmp $95
    bcc alternate_spell_palette_while_target_animation_active_c29d88
    lda a:$00B6,X
    dec
alternate_spell_palette_while_target_animation_active_c29d88:
    sta a:$00BC,X
    .i16
    ldx #$000F
    jsr copy_boss_palette_with_cpu_words
    clc
    rts
