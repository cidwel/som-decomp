.setcpu "65816"
.segment "CODE"
.org $53E4
map_control_0e53e4:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
