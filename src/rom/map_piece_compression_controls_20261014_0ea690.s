.setcpu "65816"
.segment "CODE"
.org $A690
map_control_0ea690:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
