.setcpu "65816"
.segment "CODE"
.org $608B
map_control_0d608b:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
