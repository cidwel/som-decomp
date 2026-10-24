; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-waits.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6914
restore_native_menu_actor_saved_category:
    sep #$30
    ldx a:$1808
    lda a:$1870,X
    sta a:$1809
    rep #$30
    rts
