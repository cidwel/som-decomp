.setcpu "65816"
.segment "CODE"
.org $D379
map_control_0ed379:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
