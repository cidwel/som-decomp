.setcpu "65816"
.segment "CODE"
.org $CC2A
map_control_0fcc2a:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
