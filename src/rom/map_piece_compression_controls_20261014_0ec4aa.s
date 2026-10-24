.setcpu "65816"
.segment "CODE"
.org $C4AA
map_control_0ec4aa:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
