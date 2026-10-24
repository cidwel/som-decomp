.setcpu "65816"
.segment "CODE"
.org $8EAB
map_control_0f8eab:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E4 ; previous-row copy count
