.setcpu "65816"
.segment "CODE"
.org $A37F
map_control_0fa37f:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
