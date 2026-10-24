.setcpu "65816"
.segment "CODE"
.org $512F
map_control_0f512f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
