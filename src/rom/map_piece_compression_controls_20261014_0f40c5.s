.setcpu "65816"
.segment "CODE"
.org $40C5
map_control_0f40c5:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
