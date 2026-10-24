.setcpu "65816"
.segment "CODE"
.org $5FB8
map_control_0d5fb8:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
