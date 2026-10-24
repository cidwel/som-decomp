.setcpu "65816"
.segment "CODE"
.org $6BBB
map_control_0c6bbb:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
