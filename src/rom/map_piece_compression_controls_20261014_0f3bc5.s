.setcpu "65816"
.segment "CODE"
.org $3BC5
map_control_0f3bc5:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E1 ; previous-row copy count
