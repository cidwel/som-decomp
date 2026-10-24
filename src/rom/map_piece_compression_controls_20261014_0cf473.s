.setcpu "65816"
.segment "CODE"
.org $F473
map_control_0cf473:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
