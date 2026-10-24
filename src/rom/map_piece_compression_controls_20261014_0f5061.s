.setcpu "65816"
.segment "CODE"
.org $5061
map_control_0f5061:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
