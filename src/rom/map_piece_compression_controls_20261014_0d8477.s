.setcpu "65816"
.segment "CODE"
.org $8477
map_control_0d8477:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
