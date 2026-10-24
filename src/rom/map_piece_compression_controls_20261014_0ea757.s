.setcpu "65816"
.segment "CODE"
.org $A757
map_control_0ea757:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
