.setcpu "65816"
.segment "CODE"
.org $951A
map_control_0f951a:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
