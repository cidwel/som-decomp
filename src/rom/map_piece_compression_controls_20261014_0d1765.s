.setcpu "65816"
.segment "CODE"
.org $1765
map_control_0d1765:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
