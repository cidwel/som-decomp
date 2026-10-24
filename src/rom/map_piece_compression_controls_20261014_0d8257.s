.setcpu "65816"
.segment "CODE"
.org $8257
map_control_0d8257:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
