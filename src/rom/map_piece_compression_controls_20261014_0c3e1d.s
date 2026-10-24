.setcpu "65816"
.segment "CODE"
.org $3E1D
map_control_0c3e1d:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
