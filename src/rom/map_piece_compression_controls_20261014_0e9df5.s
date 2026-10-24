.setcpu "65816"
.segment "CODE"
.org $9DF5
map_control_0e9df5:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
