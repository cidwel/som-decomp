.setcpu "65816"
.segment "CODE"
.org $CAC7
map_control_0fcac7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
