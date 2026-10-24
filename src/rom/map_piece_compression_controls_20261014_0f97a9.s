.setcpu "65816"
.segment "CODE"
.org $97A9
map_control_0f97a9:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
