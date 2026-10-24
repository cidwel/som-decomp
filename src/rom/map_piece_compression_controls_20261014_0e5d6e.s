.setcpu "65816"
.segment "CODE"
.org $5D6E
map_control_0e5d6e:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
