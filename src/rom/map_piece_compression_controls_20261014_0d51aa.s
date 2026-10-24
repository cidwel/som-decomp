.setcpu "65816"
.segment "CODE"
.org $51AA
map_control_0d51aa:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
