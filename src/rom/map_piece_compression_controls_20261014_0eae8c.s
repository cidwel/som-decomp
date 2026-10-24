.setcpu "65816"
.segment "CODE"
.org $AE8C
map_control_0eae8c:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
