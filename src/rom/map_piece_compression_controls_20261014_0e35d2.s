.setcpu "65816"
.segment "CODE"
.org $35D2
map_control_0e35d2:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
