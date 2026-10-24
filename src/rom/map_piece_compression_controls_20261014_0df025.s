.setcpu "65816"
.segment "CODE"
.org $F025
map_control_0df025:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
