.setcpu "65816"
.segment "CODE"
.org $E651
map_control_0fe651:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
