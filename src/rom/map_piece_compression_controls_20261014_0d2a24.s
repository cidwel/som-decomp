.setcpu "65816"
.segment "CODE"
.org $2A24
map_control_0d2a24:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
