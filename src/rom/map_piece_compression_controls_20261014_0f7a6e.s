.setcpu "65816"
.segment "CODE"
.org $7A6E
map_control_0f7a6e:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
