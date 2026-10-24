.setcpu "65816"
.segment "CODE"
.org $4DCE
map_control_0c4dce:
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
