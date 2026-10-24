.setcpu "65816"
.segment "CODE"
.org $2848
map_control_0e2848:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
