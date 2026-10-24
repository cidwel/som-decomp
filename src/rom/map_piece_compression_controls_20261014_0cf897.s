.setcpu "65816"
.segment "CODE"
.org $F897
map_control_0cf897:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
