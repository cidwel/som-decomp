.setcpu "65816"
.segment "CODE"
.org $4480
map_control_0e4480:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
