.setcpu "65816"
.segment "CODE"
.org $AA4E
map_control_0eaa4e:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
