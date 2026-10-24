.setcpu "65816"
.segment "CODE"
.org $18B9
map_control_0f18b9:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
