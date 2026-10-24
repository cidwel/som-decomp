.setcpu "65816"
.segment "CODE"
.org $2287
map_control_0f2287:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E6 ; previous-row copy count
