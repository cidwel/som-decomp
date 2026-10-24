.setcpu "65816"
.segment "CODE"
.org $00D6
map_control_0f00d6:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
