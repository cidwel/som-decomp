.setcpu "65816"
.segment "CODE"
.org $E73F
map_control_0de73f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
