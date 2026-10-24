.setcpu "65816"
.segment "CODE"
.org $470C
map_control_0f470c:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $50 ; distance low bit/count
