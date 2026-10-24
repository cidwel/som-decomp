.setcpu "65816"
.segment "CODE"
.org $B2AD
map_control_0db2ad:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
