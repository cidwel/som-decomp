.setcpu "65816"
.segment "CODE"
.org $5806
map_control_0f5806:
    .byte $E3 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
