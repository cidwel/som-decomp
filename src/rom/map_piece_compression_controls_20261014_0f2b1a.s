.setcpu "65816"
.segment "CODE"
.org $2B1A
map_control_0f2b1a:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E6 ; previous-row copy count
