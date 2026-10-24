.setcpu "65816"
.segment "CODE"
.org $548E
map_control_0d548e:
    .byte $E8 ; backreference distance high bits
    .byte $5E ; distance low bit/count
