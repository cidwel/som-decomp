.setcpu "65816"
.segment "CODE"
.org $1E15
map_control_0c1e15:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
