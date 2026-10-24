.setcpu "65816"
.segment "CODE"
.org $DE9A
map_control_0fde9a:
    .byte $D3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
