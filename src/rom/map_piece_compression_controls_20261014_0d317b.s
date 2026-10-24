.setcpu "65816"
.segment "CODE"
.org $317B
map_control_0d317b:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
