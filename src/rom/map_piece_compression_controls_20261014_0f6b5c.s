.setcpu "65816"
.segment "CODE"
.org $6B5C
map_control_0f6b5c:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
