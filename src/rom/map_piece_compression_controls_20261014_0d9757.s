.setcpu "65816"
.segment "CODE"
.org $9757
map_control_0d9757:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
