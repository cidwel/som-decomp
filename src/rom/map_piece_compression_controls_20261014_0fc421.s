.setcpu "65816"
.segment "CODE"
.org $C421
map_control_0fc421:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
