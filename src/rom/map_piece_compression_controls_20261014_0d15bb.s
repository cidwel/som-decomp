.setcpu "65816"
.segment "CODE"
.org $15BB
map_control_0d15bb:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
