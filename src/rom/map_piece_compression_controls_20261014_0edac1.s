.setcpu "65816"
.segment "CODE"
.org $DAC1
map_control_0edac1:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
