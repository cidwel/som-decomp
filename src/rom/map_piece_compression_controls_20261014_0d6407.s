.setcpu "65816"
.segment "CODE"
.org $6407
map_control_0d6407:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
