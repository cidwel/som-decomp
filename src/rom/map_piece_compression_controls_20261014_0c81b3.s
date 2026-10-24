.setcpu "65816"
.segment "CODE"
.org $81B3
map_control_0c81b3:
    .byte $D2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count
