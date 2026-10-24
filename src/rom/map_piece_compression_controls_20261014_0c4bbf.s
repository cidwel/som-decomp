.setcpu "65816"
.segment "CODE"
.org $4BBF
map_control_0c4bbf:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
