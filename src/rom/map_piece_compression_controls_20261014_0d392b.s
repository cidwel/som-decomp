.setcpu "65816"
.segment "CODE"
.org $392B
map_control_0d392b:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
