.setcpu "65816"
.segment "CODE"
.org $F257
map_control_0ff257:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
