.setcpu "65816"
.segment "CODE"
.org $66C2
map_control_0c66c2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
