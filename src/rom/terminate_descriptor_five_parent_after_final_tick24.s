; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five-terminal.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $602D
terminate_descriptor_five_parent_after_final_tick24:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bcc terminate_descriptor_five_parent_after_final_tick24_c26039
    sec
    rts
terminate_descriptor_five_parent_after_final_tick24_c26039:
    clc
    rts
