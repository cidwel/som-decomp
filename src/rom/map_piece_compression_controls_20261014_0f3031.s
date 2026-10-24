.setcpu "65816"
.segment "CODE"
.org $3031
map_control_0f3031:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
