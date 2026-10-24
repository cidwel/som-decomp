.setcpu "65816"
.segment "CODE"
.org $7A7D
map_control_0f7a7d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
