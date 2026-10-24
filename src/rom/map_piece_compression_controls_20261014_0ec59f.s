.setcpu "65816"
.segment "CODE"
.org $C59F
map_control_0ec59f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
