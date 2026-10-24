.setcpu "65816"
.segment "CODE"
.org $C417
map_control_0fc417:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
