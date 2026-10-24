.setcpu "65816"
.segment "CODE"
.org $4475
map_control_0e4475:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
