.setcpu "65816"
.segment "CODE"
.org $7B9D
map_control_0c7b9d:
    .byte $C4 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E1 ; previous-row copy count
