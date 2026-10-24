.setcpu "65816"
.segment "CODE"
.org $6EFF
map_control_0d6eff:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
