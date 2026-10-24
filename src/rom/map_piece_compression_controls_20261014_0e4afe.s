.setcpu "65816"
.segment "CODE"
.org $4AFE
map_control_0e4afe:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
