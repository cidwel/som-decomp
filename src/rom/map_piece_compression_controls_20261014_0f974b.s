.setcpu "65816"
.segment "CODE"
.org $974B
map_control_0f974b:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
