.setcpu "65816"
.segment "CODE"
.org $2819
map_control_0e2819:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
