.setcpu "65816"
.segment "CODE"
.org $DE9C
map_control_0ede9c:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
