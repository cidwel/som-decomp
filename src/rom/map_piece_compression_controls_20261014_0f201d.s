.setcpu "65816"
.segment "CODE"
.org $201D
map_control_0f201d:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
