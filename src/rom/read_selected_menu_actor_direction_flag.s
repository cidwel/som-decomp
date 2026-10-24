; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-cycle.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6A41
read_selected_menu_actor_direction_flag:
    rep #$30
    lda a:$1808
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E180
    sta a:$1844
    tax
    lda f:$7E0010,X
    .a16
    and #$8000
    rts
