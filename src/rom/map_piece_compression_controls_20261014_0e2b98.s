.setcpu "65816"
.segment "CODE"
.org $2B98
map_control_0e2b98:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E7 ; previous-row copy count
