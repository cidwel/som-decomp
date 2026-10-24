.setcpu "65816"
.segment "CODE"
.org $25CB
map_control_0e25cb:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
