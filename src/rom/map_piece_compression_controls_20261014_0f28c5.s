.setcpu "65816"
.segment "CODE"
.org $28C5
map_control_0f28c5:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
