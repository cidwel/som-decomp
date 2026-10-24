.setcpu "65816"
.segment "CODE"
.org $9FA9
map_control_0f9fa9:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
