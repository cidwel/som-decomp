.setcpu "65816"
.segment "CODE"
.org $5C0F
map_control_0e5c0f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
