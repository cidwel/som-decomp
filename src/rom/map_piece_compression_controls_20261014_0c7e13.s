.setcpu "65816"
.segment "CODE"
.org $7E13
map_control_0c7e13:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
