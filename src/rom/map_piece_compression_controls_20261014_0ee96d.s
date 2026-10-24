.setcpu "65816"
.segment "CODE"
.org $E96D
map_control_0ee96d:
    .byte $C6 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
