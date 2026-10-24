.setcpu "65816"
.segment "CODE"
.org $6693
map_control_0d6693:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
