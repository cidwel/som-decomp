.setcpu "65816"
.segment "CODE"
.org $577D
map_control_0e577d:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
