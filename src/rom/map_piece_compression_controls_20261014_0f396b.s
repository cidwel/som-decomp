.setcpu "65816"
.segment "CODE"
.org $396B
map_control_0f396b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
