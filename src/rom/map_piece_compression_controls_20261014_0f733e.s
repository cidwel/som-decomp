.setcpu "65816"
.segment "CODE"
.org $733E
map_control_0f733e:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
