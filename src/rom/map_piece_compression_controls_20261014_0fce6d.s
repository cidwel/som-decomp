.setcpu "65816"
.segment "CODE"
.org $CE6D
map_control_0fce6d:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
