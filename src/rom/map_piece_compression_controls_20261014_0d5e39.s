.setcpu "65816"
.segment "CODE"
.org $5E39
map_control_0d5e39:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E2 ; previous-row copy count
