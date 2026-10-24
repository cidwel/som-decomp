.setcpu "65816"
.segment "CODE"
.org $97D6
map_control_0f97d6:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
