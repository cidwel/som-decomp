.setcpu "65816"
.segment "CODE"
.org $8A0D
map_control_0f8a0d:
    .byte $CD ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
