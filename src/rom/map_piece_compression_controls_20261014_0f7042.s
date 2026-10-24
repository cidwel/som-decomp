.setcpu "65816"
.segment "CODE"
.org $7042
map_control_0f7042:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E5 ; previous-row copy count
