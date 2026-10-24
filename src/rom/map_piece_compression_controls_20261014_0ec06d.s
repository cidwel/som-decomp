.setcpu "65816"
.segment "CODE"
.org $C06D
map_control_0ec06d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
