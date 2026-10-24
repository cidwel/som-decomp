.setcpu "65816"
.segment "CODE"
.org $6ECD
map_control_0f6ecd:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count
