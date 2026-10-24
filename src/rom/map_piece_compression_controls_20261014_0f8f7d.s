.setcpu "65816"
.segment "CODE"
.org $8F7D
map_control_0f8f7d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
