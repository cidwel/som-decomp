.setcpu "65816"
.segment "CODE"
.org $7DF4
map_control_0f7df4:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
