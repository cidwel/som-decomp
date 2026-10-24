.setcpu "65816"
.segment "CODE"
.org $BBB3
map_control_0ebbb3:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
