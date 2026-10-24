.setcpu "65816"
.segment "CODE"
.org $861A
map_control_0f861a:
    .byte $E6 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
