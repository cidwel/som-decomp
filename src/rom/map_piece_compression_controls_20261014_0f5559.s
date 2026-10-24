.setcpu "65816"
.segment "CODE"
.org $5559
map_control_0f5559:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E2 ; previous-row copy count
