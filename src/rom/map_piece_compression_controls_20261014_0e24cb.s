.setcpu "65816"
.segment "CODE"
.org $24CB
map_control_0e24cb:
    .byte $E1 ; previous-row copy count
    .byte $F4 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
