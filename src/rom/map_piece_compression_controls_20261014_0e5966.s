.setcpu "65816"
.segment "CODE"
.org $5966
map_control_0e5966:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
