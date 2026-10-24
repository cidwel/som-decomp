.setcpu "65816"
.segment "CODE"
.org $81A1
map_control_0c81a1:
    .byte $D2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
