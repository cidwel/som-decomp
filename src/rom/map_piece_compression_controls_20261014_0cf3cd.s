.setcpu "65816"
.segment "CODE"
.org $F3CD
map_control_0cf3cd:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
