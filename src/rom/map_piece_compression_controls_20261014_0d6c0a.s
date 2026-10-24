.setcpu "65816"
.segment "CODE"
.org $6C0A
map_control_0d6c0a:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
