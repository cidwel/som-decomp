.setcpu "65816"
.segment "CODE"
.org $17C4
map_control_0e17c4:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7C ; distance low bit/count
