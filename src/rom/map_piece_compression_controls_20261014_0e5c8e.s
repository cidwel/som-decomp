.setcpu "65816"
.segment "CODE"
.org $5C8E
map_control_0e5c8e:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
