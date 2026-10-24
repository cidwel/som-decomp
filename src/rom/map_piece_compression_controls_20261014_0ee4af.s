.setcpu "65816"
.segment "CODE"
.org $E4AF
map_control_0ee4af:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
