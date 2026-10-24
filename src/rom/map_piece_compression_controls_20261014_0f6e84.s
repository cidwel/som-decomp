.setcpu "65816"
.segment "CODE"
.org $6E84
map_control_0f6e84:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
