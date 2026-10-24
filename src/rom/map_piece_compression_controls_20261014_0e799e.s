.setcpu "65816"
.segment "CODE"
.org $799E
map_control_0e799e:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $D1 ; same-value copy count/distance
    .byte $D3 ; same-value copy count/distance
