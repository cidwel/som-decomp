.setcpu "65816"
.segment "CODE"
.org $F93E
map_control_0df93e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
