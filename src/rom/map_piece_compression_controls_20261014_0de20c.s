.setcpu "65816"
.segment "CODE"
.org $E20C
map_control_0de20c:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
