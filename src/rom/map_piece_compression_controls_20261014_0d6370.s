.setcpu "65816"
.segment "CODE"
.org $6370
map_control_0d6370:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
