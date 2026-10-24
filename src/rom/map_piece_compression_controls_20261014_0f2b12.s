.setcpu "65816"
.segment "CODE"
.org $2B12
map_control_0f2b12:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
