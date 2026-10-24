.setcpu "65816"
.segment "CODE"
.org $00E6
map_control_0f00e6:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
