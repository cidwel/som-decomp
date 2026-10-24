.setcpu "65816"
.segment "CODE"
.org $B2A4
map_control_0db2a4:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
