.setcpu "65816"
.segment "CODE"
.org $56F0
map_control_0e56f0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
