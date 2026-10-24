.setcpu "65816"
.segment "CODE"
.org $B864
map_control_0fb864:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E2 ; previous-row copy count
