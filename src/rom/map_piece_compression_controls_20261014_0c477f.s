.setcpu "65816"
.segment "CODE"
.org $477F
map_control_0c477f:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
