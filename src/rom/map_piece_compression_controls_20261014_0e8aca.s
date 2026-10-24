.setcpu "65816"
.segment "CODE"
.org $8ACA
map_control_0e8aca:
    .byte $EB ; backreference distance high bits
    .byte $93 ; distance low bit/count
