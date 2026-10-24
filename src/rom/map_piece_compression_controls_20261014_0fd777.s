.setcpu "65816"
.segment "CODE"
.org $D777
map_control_0fd777:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
