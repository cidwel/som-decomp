.setcpu "65816"
.segment "CODE"
.org $3DAC
map_control_0f3dac:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
