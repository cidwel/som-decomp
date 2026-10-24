.setcpu "65816"
.segment "CODE"
.org $C84D
map_control_0ec84d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
