.setcpu "65816"
.segment "CODE"
.org $1100
map_control_0c1100:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
