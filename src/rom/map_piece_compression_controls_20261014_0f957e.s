.setcpu "65816"
.segment "CODE"
.org $957E
map_control_0f957e:
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C3 ; same-value copy count/distance
