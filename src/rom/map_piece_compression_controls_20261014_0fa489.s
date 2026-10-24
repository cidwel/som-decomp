.setcpu "65816"
.segment "CODE"
.org $A489
map_control_0fa489:
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
