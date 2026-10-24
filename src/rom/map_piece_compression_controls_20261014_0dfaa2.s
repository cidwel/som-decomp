.setcpu "65816"
.segment "CODE"
.org $FAA2
map_control_0dfaa2:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
