.setcpu "65816"
.segment "CODE"
.org $1F57
map_control_0c1f57:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
