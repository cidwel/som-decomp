.setcpu "65816"
.segment "CODE"
.org $41A1
map_control_0d41a1:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
