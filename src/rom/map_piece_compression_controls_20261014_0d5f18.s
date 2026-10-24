.setcpu "65816"
.segment "CODE"
.org $5F18
map_control_0d5f18:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
