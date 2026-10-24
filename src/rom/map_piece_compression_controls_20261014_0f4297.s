.setcpu "65816"
.segment "CODE"
.org $4297
map_control_0f4297:
    .byte $C5 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4B ; distance low bit/count
