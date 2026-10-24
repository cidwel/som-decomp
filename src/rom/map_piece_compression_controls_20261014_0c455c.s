.setcpu "65816"
.segment "CODE"
.org $455C
map_control_0c455c:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
