.setcpu "65816"
.segment "CODE"
.org $D034
map_control_0fd034:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
