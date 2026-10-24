.setcpu "65816"
.segment "CODE"
.org $0CDA
map_control_0c0cda:
    .byte $F2 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
