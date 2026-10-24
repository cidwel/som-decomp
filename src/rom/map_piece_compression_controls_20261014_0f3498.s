.setcpu "65816"
.segment "CODE"
.org $3498
map_control_0f3498:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
