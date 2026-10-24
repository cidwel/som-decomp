; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-death-particles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3C0E
plot_terminal_particle_bitplanes:
    sta $95
    .a16
    and #$FF00
    xba
    lsr
    lsr
    lsr
    xba
    asl
    sta $97
    lda $95
    .a16
    and #$00FF
    lsr
    lsr
    lsr
    xba
    lsr
    lsr
    lsr
    clc
    adc $97
    sta $97
    lda $96
    .a16
    and #$0007
    asl
    clc
    adc $97
    .a16
    adc #$6000
    sta $0C
    sep #$30
    lda $95
    .a8
    and #$07
    tax
    lda f:$C23C70,X
    sta $99
    lda $1A
    .a8
    bit #$08
    beq plot_terminal_particle_bitplanes_c23c55
    .i8
    ldy #$00
    lda $99
    ora ($0C),Y
    sta ($0C),Y
plot_terminal_particle_bitplanes_c23c55:
    .i8
    ldy #$01
    lda $99
    ora ($0C),Y
    sta ($0C),Y
    .i8
    ldy #$10
    lda $99
    ora ($0C),Y
    sta ($0C),Y
    .i8
    ldy #$11
    lda $99
    ora ($0C),Y
    sta ($0C),Y
    rep #$30
    rts
