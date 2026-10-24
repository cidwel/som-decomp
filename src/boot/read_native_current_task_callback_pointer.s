; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-task-access-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AD60
read_native_current_task_callback_pointer:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldy a:$009E
    ldx a:$000C,Y
    plb
    plp
    pld
    rts
