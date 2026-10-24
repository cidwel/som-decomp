.setcpu "65816"
.segment "CODE"
.org $D35F
map_control_0ed35f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
