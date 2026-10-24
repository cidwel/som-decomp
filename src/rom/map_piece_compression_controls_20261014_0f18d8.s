.setcpu "65816"
.segment "CODE"
.org $18D8
map_control_0f18d8:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
