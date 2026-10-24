.setcpu "65816"
.segment "CODE"
.org $6999
map_control_0d6999:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
