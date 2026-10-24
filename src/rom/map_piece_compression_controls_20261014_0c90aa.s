.setcpu "65816"
.segment "CODE"
.org $90AA
map_control_0c90aa:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
