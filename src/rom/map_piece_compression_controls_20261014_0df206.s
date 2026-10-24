.setcpu "65816"
.segment "CODE"
.org $F206
map_control_0df206:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
