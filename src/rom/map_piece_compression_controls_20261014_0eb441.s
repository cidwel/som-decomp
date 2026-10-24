.setcpu "65816"
.segment "CODE"
.org $B441
map_control_0eb441:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
