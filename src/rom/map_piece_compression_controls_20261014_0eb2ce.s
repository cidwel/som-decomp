.setcpu "65816"
.segment "CODE"
.org $B2CE
map_control_0eb2ce:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
