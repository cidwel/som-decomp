.setcpu "65816"
.segment "CODE"
.org $C403
map_control_0ec403:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
