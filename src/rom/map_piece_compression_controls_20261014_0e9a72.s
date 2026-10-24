.setcpu "65816"
.segment "CODE"
.org $9A72
map_control_0e9a72:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
