.setcpu "65816"
.segment "CODE"
.org $8DD9
map_control_0f8dd9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
