.setcpu "65816"
.segment "CODE"
.org $6C45
map_control_0f6c45:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $8B ; distance low bit/count
