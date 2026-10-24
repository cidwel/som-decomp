.setcpu "65816"
.segment "CODE"
.org $9F10
map_control_0d9f10:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
