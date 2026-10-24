.setcpu "65816"
.segment "CODE"
.org $8481
map_control_0c8481:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
