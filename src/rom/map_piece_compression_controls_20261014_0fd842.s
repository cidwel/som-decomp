.setcpu "65816"
.segment "CODE"
.org $D842
map_control_0fd842:
    .byte $E0 ; previous-row copy escape
    .byte $74 ; row-distance/count
