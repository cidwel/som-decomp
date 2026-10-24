.setcpu "65816"
.segment "CODE"
.org $F465
map_control_0ef465:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
