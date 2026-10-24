.setcpu "65816"
.segment "CODE"
.org $8681
map_control_0f8681:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $D2 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E6 ; previous-row copy count
