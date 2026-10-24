.setcpu "65816"
.segment "CODE"
.org $335B
map_control_0d335b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
