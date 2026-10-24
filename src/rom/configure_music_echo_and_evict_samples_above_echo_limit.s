; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-music-dependencies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $060A
configure_music_echo_and_evict_samples_above_echo_limit:
    php
    sep #$20
    .a8
    lda #$00
    pha
    lda $02
    .a8
    and #$0F
    asl
    asl
    pha
    plx
    lda f:$C30708,X
    sta a:$2142
    cmp $F0
    beq configure_music_echo_and_evict_samples_above_echo_limit_c30651
    sta $F0
    lda $F0
    bne configure_music_echo_and_evict_samples_above_echo_limit_c3062a
    inc
configure_music_echo_and_evict_samples_above_echo_limit_c3062a:
    asl
    asl
    asl
    .a8
    eor #$FF
    inc
    clc
    .a8
    adc #$FA
    sta $F2
    txy
    .i16
    ldx #$0000
configure_music_echo_and_evict_samples_above_echo_limit_c30639:
    lda $4B,X
    cmp $F2
    bcs configure_music_echo_and_evict_samples_above_echo_limit_c30648
    inx
    inx
    .i16
    cpx #$0020
    bne configure_music_echo_and_evict_samples_above_echo_limit_c30639
    bra configure_music_echo_and_evict_samples_above_echo_limit_c30650
configure_music_echo_and_evict_samples_above_echo_limit_c30648:
    stz $28,X
    inx
    .i16
    cpx #$0020
    bne configure_music_echo_and_evict_samples_above_echo_limit_c30648
configure_music_echo_and_evict_samples_above_echo_limit_c30650:
    tyx
configure_music_echo_and_evict_samples_above_echo_limit_c30651:
    lda f:$C30709,X
    sta a:$2143
    xba
    sta a:$2140
configure_music_echo_and_evict_samples_above_echo_limit_c3065c:
    cmp a:$2140
    bne configure_music_echo_and_evict_samples_above_echo_limit_c3065c
    inc
    xba
    lda f:$C3070A,X
    sta a:$2142
    lda f:$C3070B,X
    sta a:$2143
    xba
    sta a:$2140
configure_music_echo_and_evict_samples_above_echo_limit_c30675:
    cmp a:$2140
    bne configure_music_echo_and_evict_samples_above_echo_limit_c30675
    inc
    xba
    plp
    rts
