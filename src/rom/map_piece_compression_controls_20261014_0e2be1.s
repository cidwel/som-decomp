.setcpu "65816"
.segment "CODE"
.org $2BE1
map_control_0e2be1:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
