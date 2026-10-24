.setcpu "65816"
.segment "CODE"
.org $4C60
map_control_0f4c60:
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
