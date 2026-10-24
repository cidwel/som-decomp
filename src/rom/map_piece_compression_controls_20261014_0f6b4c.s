.setcpu "65816"
.segment "CODE"
.org $6B4C
map_control_0f6b4c:
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
