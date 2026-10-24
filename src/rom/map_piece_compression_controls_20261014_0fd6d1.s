.setcpu "65816"
.segment "CODE"
.org $D6D1
map_control_0fd6d1:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
