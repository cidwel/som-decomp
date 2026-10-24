.setcpu "65816"
.segment "CODE"
.org $FDD8
map_control_0efdd8:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
