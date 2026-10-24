.setcpu "65816"
.segment "CODE"
.org $863F
map_control_0e863f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
