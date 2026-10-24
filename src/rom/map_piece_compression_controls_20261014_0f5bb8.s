.setcpu "65816"
.segment "CODE"
.org $5BB8
map_control_0f5bb8:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
