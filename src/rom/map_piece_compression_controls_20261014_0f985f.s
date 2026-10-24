.setcpu "65816"
.segment "CODE"
.org $985F
map_control_0f985f:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
