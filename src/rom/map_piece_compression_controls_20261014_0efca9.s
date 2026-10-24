.setcpu "65816"
.segment "CODE"
.org $FCA9
map_control_0efca9:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
