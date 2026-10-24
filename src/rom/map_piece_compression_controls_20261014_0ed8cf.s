.setcpu "65816"
.segment "CODE"
.org $D8CF
map_control_0ed8cf:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $CB ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
