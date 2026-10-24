.setcpu "65816"
.segment "CODE"
.org $244B
map_control_0f244b:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
