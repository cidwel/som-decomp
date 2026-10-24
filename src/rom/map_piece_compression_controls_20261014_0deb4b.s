.setcpu "65816"
.segment "CODE"
.org $EB4B
map_control_0deb4b:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
