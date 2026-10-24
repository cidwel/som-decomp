.setcpu "65816"
.segment "CODE"
.org $3736
map_control_0f3736:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
