.setcpu "65816"
.segment "CODE"
.org $2BCC
map_control_0c2bcc:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
