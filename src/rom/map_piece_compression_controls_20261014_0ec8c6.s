.setcpu "65816"
.segment "CODE"
.org $C8C6
map_control_0ec8c6:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
