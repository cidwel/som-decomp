.setcpu "65816"
.segment "CODE"
.org $9C19
map_control_0e9c19:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
