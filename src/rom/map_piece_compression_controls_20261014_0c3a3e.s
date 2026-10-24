.setcpu "65816"
.segment "CODE"
.org $3A3E
map_control_0c3a3e:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
