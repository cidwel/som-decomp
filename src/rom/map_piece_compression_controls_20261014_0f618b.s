.setcpu "65816"
.segment "CODE"
.org $618B
map_control_0f618b:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
