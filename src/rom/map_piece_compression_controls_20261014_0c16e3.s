.setcpu "65816"
.segment "CODE"
.org $16E3
map_control_0c16e3:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
