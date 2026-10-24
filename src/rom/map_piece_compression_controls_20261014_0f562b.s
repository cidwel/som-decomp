.setcpu "65816"
.segment "CODE"
.org $562B
map_control_0f562b:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
