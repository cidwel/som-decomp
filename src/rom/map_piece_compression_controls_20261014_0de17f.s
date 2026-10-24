.setcpu "65816"
.segment "CODE"
.org $E17F
map_control_0de17f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
