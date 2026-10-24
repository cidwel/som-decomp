.setcpu "65816"
.segment "CODE"
.org $49E0
map_control_0e49e0:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
