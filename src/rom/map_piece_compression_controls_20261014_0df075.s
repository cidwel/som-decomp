.setcpu "65816"
.segment "CODE"
.org $F075
map_control_0df075:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
