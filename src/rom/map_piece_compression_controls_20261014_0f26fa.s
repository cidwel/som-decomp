.setcpu "65816"
.segment "CODE"
.org $26FA
map_control_0f26fa:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
