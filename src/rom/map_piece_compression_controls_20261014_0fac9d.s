.setcpu "65816"
.segment "CODE"
.org $AC9D
map_control_0fac9d:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
