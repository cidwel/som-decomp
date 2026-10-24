.setcpu "65816"
.segment "CODE"
.org $6CD2
map_control_0f6cd2:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
