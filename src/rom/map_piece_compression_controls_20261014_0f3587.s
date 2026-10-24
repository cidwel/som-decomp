.setcpu "65816"
.segment "CODE"
.org $3587
map_control_0f3587:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
