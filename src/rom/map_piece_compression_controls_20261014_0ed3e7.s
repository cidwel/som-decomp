.setcpu "65816"
.segment "CODE"
.org $D3E7
map_control_0ed3e7:
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $57 ; distance low bit/count
