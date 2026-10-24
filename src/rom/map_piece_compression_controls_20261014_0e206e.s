.setcpu "65816"
.segment "CODE"
.org $206E
map_control_0e206e:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
