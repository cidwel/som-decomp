.setcpu "65816"
.segment "CODE"
.org $7B90
map_control_0f7b90:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
