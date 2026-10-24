.setcpu "65816"
.segment "CODE"
.org $7E3E
map_control_0c7e3e:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
