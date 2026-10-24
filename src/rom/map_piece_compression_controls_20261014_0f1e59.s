.setcpu "65816"
.segment "CODE"
.org $1E59
map_control_0f1e59:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
