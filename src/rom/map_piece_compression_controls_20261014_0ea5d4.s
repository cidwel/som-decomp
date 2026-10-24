.setcpu "65816"
.segment "CODE"
.org $A5D4
map_control_0ea5d4:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
