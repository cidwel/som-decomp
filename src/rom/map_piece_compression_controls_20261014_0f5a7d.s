.setcpu "65816"
.segment "CODE"
.org $5A7D
map_control_0f5a7d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
