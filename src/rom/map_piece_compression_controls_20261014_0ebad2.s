.setcpu "65816"
.segment "CODE"
.org $BAD2
map_control_0ebad2:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
