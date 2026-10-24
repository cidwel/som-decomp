.setcpu "65816"
.segment "CODE"
.org $875F
map_control_0d875f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
