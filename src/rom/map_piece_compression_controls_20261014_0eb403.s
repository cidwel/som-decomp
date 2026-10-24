.setcpu "65816"
.segment "CODE"
.org $B403
map_control_0eb403:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
