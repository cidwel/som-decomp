.setcpu "65816"
.segment "CODE"
.org $4DAC
map_control_0f4dac:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
