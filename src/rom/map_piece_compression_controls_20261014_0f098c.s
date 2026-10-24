.setcpu "65816"
.segment "CODE"
.org $098C
map_control_0f098c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
