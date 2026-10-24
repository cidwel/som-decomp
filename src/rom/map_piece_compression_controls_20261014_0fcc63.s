.setcpu "65816"
.segment "CODE"
.org $CC63
map_control_0fcc63:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E4 ; previous-row copy count
