.setcpu "65816"
.segment "CODE"
.org $FB6A
map_control_0cfb6a:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
