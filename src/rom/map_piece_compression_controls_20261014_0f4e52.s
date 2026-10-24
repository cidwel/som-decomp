.setcpu "65816"
.segment "CODE"
.org $4E52
map_control_0f4e52:
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
