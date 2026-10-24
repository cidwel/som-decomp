.setcpu "65816"
.segment "CODE"
.org $F58E
map_control_0ef58e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
