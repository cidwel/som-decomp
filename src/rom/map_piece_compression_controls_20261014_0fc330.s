.setcpu "65816"
.segment "CODE"
.org $C330
map_control_0fc330:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
    .byte $D9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
