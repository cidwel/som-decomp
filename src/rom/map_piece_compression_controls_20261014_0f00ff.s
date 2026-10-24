.setcpu "65816"
.segment "CODE"
.org $00FF
map_control_0f00ff:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
