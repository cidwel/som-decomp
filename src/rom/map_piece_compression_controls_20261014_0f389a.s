.setcpu "65816"
.segment "CODE"
.org $389A
map_control_0f389a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
