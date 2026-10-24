.setcpu "65816"
.segment "CODE"
.org $90E5
map_control_0d90e5:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E2 ; previous-row copy count
