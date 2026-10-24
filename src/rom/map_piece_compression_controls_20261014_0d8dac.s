.setcpu "65816"
.segment "CODE"
.org $8DAC
map_control_0d8dac:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
