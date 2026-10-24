.setcpu "65816"
.segment "CODE"
.org $9D1A
map_control_0d9d1a:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
