.setcpu "65816"
.segment "CODE"
.org $7B64
map_control_0f7b64:
    .byte $EA ; backreference distance high bits
    .byte $86 ; distance low bit/count
