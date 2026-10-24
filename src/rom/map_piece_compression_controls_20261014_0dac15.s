.setcpu "65816"
.segment "CODE"
.org $AC15
map_control_0dac15:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
