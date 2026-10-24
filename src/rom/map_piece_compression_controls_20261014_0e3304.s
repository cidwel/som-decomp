.setcpu "65816"
.segment "CODE"
.org $3304
map_control_0e3304:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
