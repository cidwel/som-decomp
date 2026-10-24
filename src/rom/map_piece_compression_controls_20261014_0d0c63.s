.setcpu "65816"
.segment "CODE"
.org $0C63
map_control_0d0c63:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E1 ; previous-row copy count
