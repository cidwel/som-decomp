.setcpu "65816"
.segment "CODE"
.org $3BBB
map_control_0c3bbb:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
