.setcpu "65816"
.segment "CODE"
.org $5B0E
map_control_0d5b0e:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $52 ; distance low bit/count
