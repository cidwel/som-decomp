.setcpu "65816"
.segment "CODE"
.org $8470
map_control_0c8470:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
