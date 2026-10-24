.setcpu "65816"
.segment "CODE"
.org $66A9
map_control_0c66a9:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
