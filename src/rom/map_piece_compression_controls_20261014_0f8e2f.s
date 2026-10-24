.setcpu "65816"
.segment "CODE"
.org $8E2F
map_control_0f8e2f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
