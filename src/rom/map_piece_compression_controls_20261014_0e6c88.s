.setcpu "65816"
.segment "CODE"
.org $6C88
map_control_0e6c88:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
