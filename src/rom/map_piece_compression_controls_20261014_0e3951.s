.setcpu "65816"
.segment "CODE"
.org $3951
map_control_0e3951:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
