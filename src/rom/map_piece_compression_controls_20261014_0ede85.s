.setcpu "65816"
.segment "CODE"
.org $DE85
map_control_0ede85:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
