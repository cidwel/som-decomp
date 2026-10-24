.setcpu "65816"
.segment "CODE"
.org $815B
map_control_0c815b:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count
