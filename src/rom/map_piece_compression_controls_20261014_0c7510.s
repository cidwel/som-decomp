.setcpu "65816"
.segment "CODE"
.org $7510
map_control_0c7510:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
