.setcpu "65816"
.segment "CODE"
.org $8BBB
map_control_0e8bbb:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
