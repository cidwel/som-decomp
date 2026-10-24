.setcpu "65816"
.segment "CODE"
.org $7820
map_control_0e7820:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E1 ; previous-row copy count
