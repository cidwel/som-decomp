.setcpu "65816"
.segment "CODE"
.org $E1F1
map_control_0ee1f1:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
