.setcpu "65816"
.segment "CODE"
.org $6C3A
map_control_0d6c3a:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
