.setcpu "65816"
.segment "CODE"
.org $7EDC
map_control_0c7edc:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
