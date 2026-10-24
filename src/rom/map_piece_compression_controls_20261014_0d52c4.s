.setcpu "65816"
.segment "CODE"
.org $52C4
map_control_0d52c4:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
