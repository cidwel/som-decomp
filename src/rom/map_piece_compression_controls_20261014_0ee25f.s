.setcpu "65816"
.segment "CODE"
.org $E25F
map_control_0ee25f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
