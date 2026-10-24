; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-twelve-death-action.md.
.setcpu "65816"
.smart
.a8
.i16

create_randomly_positioned_boss_death_explosion_actor = $0C33
rotate_fourteen_colors_in_each_selected_boss_palette = $0C89

.segment "CODE"
.org $5576
advance_descriptor_twelve_death_explosion_and_palette_action:
    lda a:$0096,X
    .a16
    and #$0003
    bne advance_descriptor_twelve_death_explosion_and_palette_action_c25581
    jsr create_randomly_positioned_boss_death_explosion_actor
advance_descriptor_twelve_death_explosion_and_palette_action_c25581:
    jsr rotate_fourteen_colors_in_each_selected_boss_palette
    clc
    rts
