.setcpu "65816"
.segment "CODE"
.org $4389
map_control_0e4389:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
