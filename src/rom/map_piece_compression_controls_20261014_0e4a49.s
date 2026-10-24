.setcpu "65816"
.segment "CODE"
.org $4A49
map_control_0e4a49:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
