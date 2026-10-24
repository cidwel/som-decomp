.setcpu "65816"
.segment "CODE"
.org $5C99
map_control_0e5c99:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
