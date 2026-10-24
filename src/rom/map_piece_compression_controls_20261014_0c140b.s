.setcpu "65816"
.segment "CODE"
.org $140B
map_control_0c140b:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $48 ; distance low bit/count
