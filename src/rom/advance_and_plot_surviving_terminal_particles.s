; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16

plot_terminal_particle_bitplanes = $3C0E

.segment "CODE"
.org $3B2A
advance_and_plot_surviving_terminal_particles:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$004B
    bcc advance_and_plot_surviving_terminal_particles_c23b36
    sec
    rts
advance_and_plot_surviving_terminal_particles_c23b36:
    asl
    asl
    asl
    sta $1C
    asl
    clc
    adc $1C
    sta $1C
    .a16
    lda #$2800
    sec
    sbc $1C
    sta $1C
    phb
    sep #$20
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$2000
    sta $1A
advance_and_plot_surviving_terminal_particles_c23b57:
    ldy $1A
    lda a:$0004,Y
    clc
    adc a:$0000,Y
    .a16
    cmp #$8000
    bcs advance_and_plot_surviving_terminal_particles_c23b81
    sta a:$0000,Y
    lda a:$0006,Y
    clc
    adc a:$0002,Y
    .a16
    cmp #$4000
    bcs advance_and_plot_surviving_terminal_particles_c23b81
    sta a:$0002,Y
    sep #$20
    lda a:$0001,Y
    rep #$20
    jsr plot_terminal_particle_bitplanes
advance_and_plot_surviving_terminal_particles_c23b81:
    lda $1A
    clc
    .a16
    adc #$0008
    sta $1A
    cmp $1C
    bcc advance_and_plot_surviving_terminal_particles_c23b57
    plb
    ldx $87
    .a16
    lda #$0001
    sta a:$0351
    clc
    rts
