.setcpu "65816"
.segment "CODE"
.org $E9FB
map_control_0ee9fb:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
