.setcpu "65816"
.segment "CODE"
.org $DE14
map_control_0ede14:
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
