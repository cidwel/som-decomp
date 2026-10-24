.setcpu "65816"
.segment "CODE"
.org $7DF0
map_control_0c7df0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
