.setcpu "65816"
.segment "CODE"
.org $360F
map_control_0e360f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
