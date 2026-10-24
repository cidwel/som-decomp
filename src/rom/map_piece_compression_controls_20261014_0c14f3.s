.setcpu "65816"
.segment "CODE"
.org $14F3
map_control_0c14f3:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
