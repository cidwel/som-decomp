.setcpu "65816"
.segment "CODE"
.org $8EFF
map_control_0e8eff:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
