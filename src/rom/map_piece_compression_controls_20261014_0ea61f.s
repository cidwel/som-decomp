.setcpu "65816"
.segment "CODE"
.org $A61F
map_control_0ea61f:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $F1 ; progressive-copy count
