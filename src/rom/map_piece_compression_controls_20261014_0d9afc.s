.setcpu "65816"
.segment "CODE"
.org $9AFC
map_control_0d9afc:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
