.setcpu "65816"
.segment "CODE"
.org $3DAC
map_control_0c3dac:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
