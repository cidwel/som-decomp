.setcpu "65816"
.segment "CODE"
.org $D343
map_control_0dd343:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
