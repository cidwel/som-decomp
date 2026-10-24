.setcpu "65816"
.segment "CODE"
.org $720B
map_control_0e720b:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
