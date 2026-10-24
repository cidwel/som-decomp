.setcpu "65816"
.segment "CODE"
.org $275C
map_control_0d275c:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
