.setcpu "65816"
.segment "CODE"
.org $BB4A
map_control_0dbb4a:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
