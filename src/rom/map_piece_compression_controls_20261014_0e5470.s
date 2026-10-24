.setcpu "65816"
.segment "CODE"
.org $5470
map_control_0e5470:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
