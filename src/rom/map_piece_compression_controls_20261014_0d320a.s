.setcpu "65816"
.segment "CODE"
.org $320A
map_control_0d320a:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
