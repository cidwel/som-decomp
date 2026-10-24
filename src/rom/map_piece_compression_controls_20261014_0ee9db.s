.setcpu "65816"
.segment "CODE"
.org $E9DB
map_control_0ee9db:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C7 ; same-value copy count/distance
