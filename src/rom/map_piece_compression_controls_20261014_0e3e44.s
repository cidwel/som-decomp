.setcpu "65816"
.segment "CODE"
.org $3E44
map_control_0e3e44:
    .byte $F2 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
