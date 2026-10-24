.setcpu "65816"
.segment "CODE"
.org $93BC
map_control_0d93bc:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
