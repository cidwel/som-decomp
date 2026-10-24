.setcpu "65816"
.segment "CODE"
.org $C0E0
map_control_0fc0e0:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
