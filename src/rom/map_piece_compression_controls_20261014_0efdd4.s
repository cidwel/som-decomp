.setcpu "65816"
.segment "CODE"
.org $FDD4
map_control_0efdd4:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
