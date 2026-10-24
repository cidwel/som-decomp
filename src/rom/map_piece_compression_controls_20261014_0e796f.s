.setcpu "65816"
.segment "CODE"
.org $796F
map_control_0e796f:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
