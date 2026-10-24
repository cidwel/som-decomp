.setcpu "65816"
.segment "CODE"
.org $586C
map_control_0f586c:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
