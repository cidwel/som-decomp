.setcpu "65816"
.segment "CODE"
.org $569E
map_control_0c569e:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
