.setcpu "65816"
.segment "CODE"
.org $739F
map_control_0c739f:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
