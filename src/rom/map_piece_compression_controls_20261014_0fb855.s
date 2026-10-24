.setcpu "65816"
.segment "CODE"
.org $B855
map_control_0fb855:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
