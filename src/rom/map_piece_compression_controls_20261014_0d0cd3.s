.setcpu "65816"
.segment "CODE"
.org $0CD3
map_control_0d0cd3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
