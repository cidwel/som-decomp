.setcpu "65816"
.segment "CODE"
.org $CEF5
map_control_0ecef5:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
