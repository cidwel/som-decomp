.setcpu "65816"
.segment "CODE"
.org $ED59
map_control_0eed59:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
