.setcpu "65816"
.segment "CODE"
.org $1B0F
map_control_0f1b0f:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
