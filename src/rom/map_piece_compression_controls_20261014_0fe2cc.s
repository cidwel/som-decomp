.setcpu "65816"
.segment "CODE"
.org $E2CC
map_control_0fe2cc:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E1 ; previous-row copy count
