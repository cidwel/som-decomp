; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1936
set_dialogue_graphics_transfer_size_preserving_status:
    php
    rep #$20
    sta f:$001D08
    plp
    rts
