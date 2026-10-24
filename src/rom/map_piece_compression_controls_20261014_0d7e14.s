.setcpu "65816"
.segment "CODE"
.org $7E14
map_control_0d7e14:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E3 ; previous-row copy count
