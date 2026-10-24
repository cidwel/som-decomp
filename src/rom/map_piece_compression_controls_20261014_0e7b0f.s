.setcpu "65816"
.segment "CODE"
.org $7B0F
map_control_0e7b0f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
