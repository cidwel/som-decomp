.setcpu "65816"
.segment "CODE"
.org $085E
map_control_0f085e:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
