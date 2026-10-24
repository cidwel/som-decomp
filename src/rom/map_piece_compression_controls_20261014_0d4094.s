.setcpu "65816"
.segment "CODE"
.org $4094
map_control_0d4094:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
