.setcpu "65816"
.segment "CODE"
.org $AEF3
map_control_0daef3:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E5 ; previous-row copy count
