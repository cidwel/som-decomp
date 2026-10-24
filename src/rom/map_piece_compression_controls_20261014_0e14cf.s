.setcpu "65816"
.segment "CODE"
.org $14CF
map_control_0e14cf:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
