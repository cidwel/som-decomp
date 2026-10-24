.setcpu "65816"
.segment "CODE"
.org $8A3E
map_control_0f8a3e:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
