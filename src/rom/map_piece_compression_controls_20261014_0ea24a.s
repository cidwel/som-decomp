.setcpu "65816"
.segment "CODE"
.org $A24A
map_control_0ea24a:
    .byte $E8 ; backreference distance high bits
    .byte $2B ; distance low bit/count
