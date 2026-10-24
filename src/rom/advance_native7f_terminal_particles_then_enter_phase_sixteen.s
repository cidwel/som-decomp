; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D
boss_external_actor_command_if_selected = $3963
create_randomly_positioned_boss_death_explosion_actor = $0C33
public_actor_death_jump = $C0006F
rotate_fourteen_colors_in_each_selected_boss_palette = $0C89

.segment "CODE"
.org $96F8
advance_native7f_terminal_particles_then_enter_phase_sixteen:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bne advance_native7f_terminal_particles_then_enter_phase_sixteen_c2970d
    ldx $87
    jsl f:public_actor_death_jump
    ldx $87
    lda a:$0096,X
advance_native7f_terminal_particles_then_enter_phase_sixteen_c2970d:
    .a16
    cmp #$0034
    bcs advance_native7f_terminal_particles_then_enter_phase_sixteen_c2971f
    .a16
    and #$0003
    bne advance_native7f_terminal_particles_then_enter_phase_sixteen_c2971a
    jsr create_randomly_positioned_boss_death_explosion_actor
advance_native7f_terminal_particles_then_enter_phase_sixteen_c2971a:
    jsr rotate_fourteen_colors_in_each_selected_boss_palette
    clc
    rts
advance_native7f_terminal_particles_then_enter_phase_sixteen_c2971f:
    stz a:$00A7,X
    .a16
    lda #$0010
    sta a:$0094,X
    stz a:$0096,X
    .a16
    lda #$0080
    sta a:$00B0,X
    sta a:$00B2,X
    stz a:$00B4,X
    stz a:$00B6,X
    stz a:$00B8,X
    stz a:$00BA,X
    stz a:$00BC,X
    .i16
    ldx #$0086
    .i16
    ldy #$0004
    .a16
    lda #$01E0
    jsr allocate_boss_palette_transition_object
    .i16
    ldx #$0086
    .i16
    ldy #$0005
    .a16
    lda #$01E0
    jsr allocate_boss_palette_transition_object
    .i16
    ldx #$0086
    .i16
    ldy #$0006
    .a16
    lda #$01E0
    jsr allocate_boss_palette_transition_object
    .i16
    ldx #$0086
    .i16
    ldy #$0007
    .a16
    lda #$01E0
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$8A00
    jsr boss_external_actor_command_if_selected
    clc
    rts
