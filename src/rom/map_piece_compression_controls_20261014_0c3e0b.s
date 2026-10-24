.setcpu "65816"
.segment "CODE"
.org $3E0B
map_control_0c3e0b:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
