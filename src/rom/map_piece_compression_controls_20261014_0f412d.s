.setcpu "65816"
.segment "CODE"
.org $412D
map_control_0f412d:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
