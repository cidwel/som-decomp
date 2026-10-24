.setcpu "65816"
.segment "CODE"
.org $80E3
map_control_0e80e3:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
