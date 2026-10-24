.setcpu "65816"
.segment "CODE"
.org $2803
map_control_0d2803:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
