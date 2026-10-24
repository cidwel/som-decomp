.setcpu "65816"
.segment "CODE"
.org $2F27
map_control_0f2f27:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
