.setcpu "65816"
.segment "CODE"
.org $D9DB
map_control_0ed9db:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
