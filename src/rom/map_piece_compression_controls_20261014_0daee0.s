.setcpu "65816"
.segment "CODE"
.org $AEE0
map_control_0daee0:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
