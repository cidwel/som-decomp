.setcpu "65816"
.segment "CODE"
.org $1D97
map_control_0f1d97:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
