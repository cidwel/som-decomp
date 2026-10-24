.setcpu "65816"
.segment "CODE"
.org $00C8
map_control_0e00c8:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
