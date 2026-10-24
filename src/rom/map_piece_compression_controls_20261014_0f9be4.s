.setcpu "65816"
.segment "CODE"
.org $9BE4
map_control_0f9be4:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
