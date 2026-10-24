.setcpu "65816"
.segment "CODE"
.org $4897
map_control_0d4897:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
