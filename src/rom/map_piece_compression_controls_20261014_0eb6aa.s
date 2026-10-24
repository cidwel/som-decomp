.setcpu "65816"
.segment "CODE"
.org $B6AA
map_control_0eb6aa:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
