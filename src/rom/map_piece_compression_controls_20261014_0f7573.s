.setcpu "65816"
.segment "CODE"
.org $7573
map_control_0f7573:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
