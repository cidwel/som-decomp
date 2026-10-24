.setcpu "65816"
.segment "CODE"
.org $F573
map_control_0ff573:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
