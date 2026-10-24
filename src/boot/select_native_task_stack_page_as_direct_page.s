; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-particle-initialize.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AD41
select_native_task_stack_page_as_direct_page:
    php
    rep #$20
    tsc
    .a16
    and #$1F00
    tcd
    plp
    rts
