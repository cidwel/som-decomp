.setcpu "65816"
.segment "CODE"
.org $4F7B
map_control_0c4f7b:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
