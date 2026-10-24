.setcpu "65816"
.segment "CODE"
.org $7726
map_control_0f7726:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E2 ; previous-row copy count
