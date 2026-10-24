.setcpu "65816"
.segment "CODE"
.org $EB68
map_control_0deb68:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
