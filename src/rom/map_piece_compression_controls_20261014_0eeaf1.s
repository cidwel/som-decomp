.setcpu "65816"
.segment "CODE"
.org $EAF1
map_control_0eeaf1:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
