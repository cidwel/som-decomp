.setcpu "65816"
.segment "CODE"
.org $24E9
map_control_0c24e9:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
