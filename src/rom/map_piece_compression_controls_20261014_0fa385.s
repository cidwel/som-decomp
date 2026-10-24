.setcpu "65816"
.segment "CODE"
.org $A385
map_control_0fa385:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $F1 ; progressive-copy count
