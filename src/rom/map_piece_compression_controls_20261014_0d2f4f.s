.setcpu "65816"
.segment "CODE"
.org $2F4F
map_control_0d2f4f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
