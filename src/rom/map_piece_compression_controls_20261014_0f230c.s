.setcpu "65816"
.segment "CODE"
.org $230C
map_control_0f230c:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
