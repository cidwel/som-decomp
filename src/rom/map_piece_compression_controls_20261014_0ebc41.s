.setcpu "65816"
.segment "CODE"
.org $BC41
map_control_0ebc41:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $11 ; distance low bit/count
