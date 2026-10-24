.setcpu "65816"
.segment "CODE"
.org $2025
map_control_0e2025:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E2 ; previous-row copy count
