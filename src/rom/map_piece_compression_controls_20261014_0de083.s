.setcpu "65816"
.segment "CODE"
.org $E083
map_control_0de083:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
