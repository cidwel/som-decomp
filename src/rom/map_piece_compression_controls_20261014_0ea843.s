.setcpu "65816"
.segment "CODE"
.org $A843
map_control_0ea843:
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
