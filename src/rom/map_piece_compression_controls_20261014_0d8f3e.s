.setcpu "65816"
.segment "CODE"
.org $8F3E
map_control_0d8f3e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
