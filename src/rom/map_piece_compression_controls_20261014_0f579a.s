.setcpu "65816"
.segment "CODE"
.org $579A
map_control_0f579a:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
