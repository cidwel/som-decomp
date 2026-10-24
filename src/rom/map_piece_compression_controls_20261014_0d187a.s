.setcpu "65816"
.segment "CODE"
.org $187A
map_control_0d187a:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
