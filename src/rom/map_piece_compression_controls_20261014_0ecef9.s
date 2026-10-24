.setcpu "65816"
.segment "CODE"
.org $CEF9
map_control_0ecef9:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
