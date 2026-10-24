.setcpu "65816"
.segment "CODE"
.org $F41E
map_control_0ef41e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
