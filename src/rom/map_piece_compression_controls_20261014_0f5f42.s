.setcpu "65816"
.segment "CODE"
.org $5F42
map_control_0f5f42:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
