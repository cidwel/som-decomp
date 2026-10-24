.setcpu "65816"
.segment "CODE"
.org $E996
map_control_0de996:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
