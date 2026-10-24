.setcpu "65816"
.segment "CODE"
.org $4746
map_control_0d4746:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
