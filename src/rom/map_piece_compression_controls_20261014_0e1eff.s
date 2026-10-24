.setcpu "65816"
.segment "CODE"
.org $1EFF
map_control_0e1eff:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
