.setcpu "65816"
.segment "CODE"
.org $EAE5
map_control_0eeae5:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
