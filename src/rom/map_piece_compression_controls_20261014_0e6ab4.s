.setcpu "65816"
.segment "CODE"
.org $6AB4
map_control_0e6ab4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
