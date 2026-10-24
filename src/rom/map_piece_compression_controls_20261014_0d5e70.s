.setcpu "65816"
.segment "CODE"
.org $5E70
map_control_0d5e70:
    .byte $C9 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
