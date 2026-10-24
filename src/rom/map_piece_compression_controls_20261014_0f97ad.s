.setcpu "65816"
.segment "CODE"
.org $97AD
map_control_0f97ad:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
