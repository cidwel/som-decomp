.setcpu "65816"
.segment "CODE"
.org $996B
map_control_0f996b:
    .byte $ED ; backreference distance high bits
    .byte $95 ; distance low bit/count
