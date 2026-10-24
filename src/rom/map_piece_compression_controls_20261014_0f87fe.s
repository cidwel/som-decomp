.setcpu "65816"
.segment "CODE"
.org $87FE
map_control_0f87fe:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
