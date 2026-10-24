.setcpu "65816"
.segment "CODE"
.org $46AA
map_control_0d46aa:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
