.setcpu "65816"
.segment "CODE"
.org $457C
map_control_0d457c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
