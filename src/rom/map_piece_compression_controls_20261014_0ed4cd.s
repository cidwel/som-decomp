.setcpu "65816"
.segment "CODE"
.org $D4CD
map_control_0ed4cd:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
