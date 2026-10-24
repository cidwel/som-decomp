; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-reserved-title-api.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CE62
reserved_native_title_status_and_direct_page_api:
    phd
    php
    rep #$30
    sep #$20
    plp
    pld
    rts
