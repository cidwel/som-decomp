.setcpu "65816"
.segment "CODE"
.org $79F0
map_control_0c79f0:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
