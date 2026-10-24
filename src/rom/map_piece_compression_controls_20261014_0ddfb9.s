.setcpu "65816"
.segment "CODE"
.org $DFB9
map_control_0ddfb9:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
