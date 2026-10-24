.setcpu "65816"
.segment "CODE"
.org $B4E9
map_control_0fb4e9:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
