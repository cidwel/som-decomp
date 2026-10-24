; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

boss_death_initialization_reserved_return = $0B4F
boss_external_actor_command_if_selected = $3963
copy_boss_palette_with_cpu_words = $26F9
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7A82
seed_descriptor_ten_final_animation_flags_event_and_palette:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$9811
    sta a:$0098,X
    .a16
    lda #$015C
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0096,X
    jsr boss_death_initialization_reserved_return
    .a16
    lda #$8A00
    jsr boss_external_actor_command_if_selected
    .a16
    lda #$0048
    .i16
    ldx #$000F
    jsr copy_boss_palette_with_cpu_words
    clc
    rts
