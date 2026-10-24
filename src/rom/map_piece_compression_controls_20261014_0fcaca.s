.setcpu "65816"
.segment "CODE"
.org $CACA
map_control_0fcaca:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
