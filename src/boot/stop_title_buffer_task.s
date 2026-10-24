; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

cleanup_title_buffer_resources = $8CA6

.segment "CODE"
.org $8DA0
stop_title_buffer_task:
    phd
    php
    rep #$30
    sep #$20
    jsr cleanup_title_buffer_resources
    plp
    pld
    rts
