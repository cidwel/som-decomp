.setcpu "65816"
.segment "CODE"
.org $154F
map_control_0d154f:
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
