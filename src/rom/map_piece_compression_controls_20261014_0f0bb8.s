.setcpu "65816"
.segment "CODE"
.org $0BB8
map_control_0f0bb8:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
