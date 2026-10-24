.setcpu "65816"
.segment "CODE"
.org $7555
map_control_0e7555:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
