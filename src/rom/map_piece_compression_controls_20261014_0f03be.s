.setcpu "65816"
.segment "CODE"
.org $03BE
map_control_0f03be:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
    .byte $E2 ; previous-row copy count
