.setcpu "65816"
.segment "CODE"
.org $261E
map_control_0f261e:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
