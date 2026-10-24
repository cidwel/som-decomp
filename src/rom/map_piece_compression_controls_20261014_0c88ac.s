.setcpu "65816"
.segment "CODE"
.org $88AC
map_control_0c88ac:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
