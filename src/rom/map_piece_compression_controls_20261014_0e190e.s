.setcpu "65816"
.segment "CODE"
.org $190E
map_control_0e190e:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
