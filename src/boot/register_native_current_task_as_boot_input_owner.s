; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-input-ownership.md.
.setcpu "65816"
.smart
.a8
.i16

current_task_id = $ACE9

.segment "CODE"
.org $A4C2
register_native_current_task_as_boot_input_owner:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    jsr current_task_id
    sta a:$0097
    plb
    plp
    pld
    rts
