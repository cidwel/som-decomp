.setcpu "65816"
.segment "CODE"
.org $6375
map_control_0d6375:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
