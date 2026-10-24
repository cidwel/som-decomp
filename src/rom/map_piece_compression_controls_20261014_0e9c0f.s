.setcpu "65816"
.segment "CODE"
.org $9C0F
map_control_0e9c0f:
    .byte $E0 ; previous-row copy escape
    .byte $FA ; row-distance/count
