.setcpu "65816"
.segment "CODE"
.org $ACB2
map_control_0dacb2:
    .byte $E5 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
