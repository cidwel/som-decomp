.setcpu "65816"
.segment "CODE"
.org $7F83
map_control_0e7f83:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
