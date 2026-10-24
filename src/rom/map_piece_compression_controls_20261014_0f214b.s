.setcpu "65816"
.segment "CODE"
.org $214B
map_control_0f214b:
    .byte $E8 ; backreference distance high bits
    .byte $7E ; distance low bit/count
