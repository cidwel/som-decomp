.setcpu "65816"
.segment "CODE"
.org $9168
map_control_0f9168:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
