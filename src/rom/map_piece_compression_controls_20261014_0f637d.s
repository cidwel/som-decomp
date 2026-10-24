.setcpu "65816"
.segment "CODE"
.org $637D
map_control_0f637d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
