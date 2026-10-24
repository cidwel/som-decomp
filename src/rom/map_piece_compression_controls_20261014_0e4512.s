.setcpu "65816"
.segment "CODE"
.org $4512
map_control_0e4512:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
