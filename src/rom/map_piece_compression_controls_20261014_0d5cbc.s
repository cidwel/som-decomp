.setcpu "65816"
.segment "CODE"
.org $5CBC
map_control_0d5cbc:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
