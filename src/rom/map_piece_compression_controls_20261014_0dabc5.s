.setcpu "65816"
.segment "CODE"
.org $ABC5
map_control_0dabc5:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
