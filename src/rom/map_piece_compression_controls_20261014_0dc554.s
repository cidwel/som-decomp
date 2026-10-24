.setcpu "65816"
.segment "CODE"
.org $C554
map_control_0dc554:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
