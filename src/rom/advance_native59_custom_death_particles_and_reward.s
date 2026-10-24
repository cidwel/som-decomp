; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-actions.md.
.setcpu "65816"
.smart
.a8
.i16

boss_external_actor_command_if_selected = $3963
create_randomly_positioned_boss_death_explosion_actor = $0C33
public_actor_death_jump = $C0006F
rotate_fourteen_colors_in_each_selected_boss_palette = $0C89

.segment "CODE"
.org $8829
advance_native59_custom_death_particles_and_reward:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bne advance_native59_custom_death_particles_and_reward_c2883c
    jsl f:public_actor_death_jump
    ldx $87
    lda a:$0096,X
advance_native59_custom_death_particles_and_reward_c2883c:
    .a16
    cmp #$0030
    bcs advance_native59_custom_death_particles_and_reward_c2884e
    .a16
    and #$0003
    bne advance_native59_custom_death_particles_and_reward_c28849
    jsr create_randomly_positioned_boss_death_explosion_actor
advance_native59_custom_death_particles_and_reward_c28849:
    jsr rotate_fourteen_colors_in_each_selected_boss_palette
    clc
    rts
advance_native59_custom_death_particles_and_reward_c2884e:
    stz a:$00A7,X
    inc a:$0094,X
    stz a:$0096,X
    .a16
    lda #$8A00
    jsr boss_external_actor_command_if_selected
    clc
    rts
