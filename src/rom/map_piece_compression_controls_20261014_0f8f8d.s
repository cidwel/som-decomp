.setcpu "65816"
.segment "CODE"
.org $8F8D
map_control_0f8f8d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
