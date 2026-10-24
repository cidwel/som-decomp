.setcpu "65816"
.segment "CODE"
.org $8DD8
map_control_0d8dd8:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E1 ; previous-row copy count
