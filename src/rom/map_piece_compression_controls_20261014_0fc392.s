.setcpu "65816"
.segment "CODE"
.org $C392
map_control_0fc392:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $D6 ; row-distance/count
    .byte $E6 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
