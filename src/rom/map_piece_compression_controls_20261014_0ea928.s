.setcpu "65816"
.segment "CODE"
.org $A928
map_control_0ea928:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
