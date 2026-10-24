.setcpu "65816"
.segment "CODE"
.org $3332
map_control_0f3332:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
