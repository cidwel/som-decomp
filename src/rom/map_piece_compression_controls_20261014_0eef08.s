.setcpu "65816"
.segment "CODE"
.org $EF08
map_control_0eef08:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
