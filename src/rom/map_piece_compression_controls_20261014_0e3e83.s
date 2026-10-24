.setcpu "65816"
.segment "CODE"
.org $3E83
map_control_0e3e83:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
