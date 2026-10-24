.setcpu "65816"
.segment "CODE"
.org $E66B
map_control_0fe66b:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
