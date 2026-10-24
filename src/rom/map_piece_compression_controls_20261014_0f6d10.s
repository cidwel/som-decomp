.setcpu "65816"
.segment "CODE"
.org $6D10
map_control_0f6d10:
    .byte $E9 ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E1 ; previous-row copy count
