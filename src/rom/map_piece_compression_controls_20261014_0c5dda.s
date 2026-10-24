.setcpu "65816"
.segment "CODE"
.org $5DDA
map_control_0c5dda:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
