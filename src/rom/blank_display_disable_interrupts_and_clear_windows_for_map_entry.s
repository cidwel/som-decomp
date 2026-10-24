; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-entry-requests.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $87C4
blank_display_disable_interrupts_and_clear_windows_for_map_entry:
    sep #$30
    .a8
    lda #$8F
    sta a:$2100
    .a8
    lda #$01
    sta a:$4200
    stz a:$420C
    stz a:$2123
    stz a:$2124
    stz a:$2125
    stz a:$2125
    rts
