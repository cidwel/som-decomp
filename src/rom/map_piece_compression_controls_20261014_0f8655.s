.setcpu "65816"
.segment "CODE"
.org $8655
map_control_0f8655:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
