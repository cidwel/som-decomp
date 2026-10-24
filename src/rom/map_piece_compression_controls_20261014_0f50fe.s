.setcpu "65816"
.segment "CODE"
.org $50FE
map_control_0f50fe:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E7 ; previous-row copy count
