.setcpu "65816"
.segment "CODE"
.org $35E2
map_control_0f35e2:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
