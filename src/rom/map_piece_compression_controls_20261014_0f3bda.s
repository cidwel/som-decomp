.setcpu "65816"
.segment "CODE"
.org $3BDA
map_control_0f3bda:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
