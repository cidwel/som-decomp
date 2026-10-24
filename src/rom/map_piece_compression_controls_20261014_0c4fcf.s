.setcpu "65816"
.segment "CODE"
.org $4FCF
map_control_0c4fcf:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
