.setcpu "65816"
.segment "CODE"
.org $0CAA
map_control_0d0caa:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
