; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $ACD0
current_task_parent_id:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .a8
    lda #$01
    ldx a:$009E
    beq current_task_parent_id_ace5
    lda a:$0005,X
current_task_parent_id_ace5:
    plb
    plp
    pld
    rts
