.setcpu "65816"
.segment "CODE"
.org $2021
map_control_0e2021:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E2 ; previous-row copy count
