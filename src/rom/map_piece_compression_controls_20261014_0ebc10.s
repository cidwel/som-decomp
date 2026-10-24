.setcpu "65816"
.segment "CODE"
.org $BC10
map_control_0ebc10:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
