.setcpu "65816"
.segment "CODE"
.org $9C6E
map_control_0f9c6e:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
