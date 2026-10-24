.setcpu "65816"
.segment "CODE"
.org $3EFD
map_control_0c3efd:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D4 ; same-value copy count/distance
