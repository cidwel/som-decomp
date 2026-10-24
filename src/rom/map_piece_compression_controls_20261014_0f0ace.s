.setcpu "65816"
.segment "CODE"
.org $0ACE
map_control_0f0ace:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
