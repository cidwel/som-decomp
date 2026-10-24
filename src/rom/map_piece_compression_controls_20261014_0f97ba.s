.setcpu "65816"
.segment "CODE"
.org $97BA
map_control_0f97ba:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
