.setcpu "65816"
.segment "CODE"
.org $BAF1
map_control_0ebaf1:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
