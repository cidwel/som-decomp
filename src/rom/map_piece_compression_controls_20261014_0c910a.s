.setcpu "65816"
.segment "CODE"
.org $910A
map_control_0c910a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
