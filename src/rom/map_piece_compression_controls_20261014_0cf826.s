.setcpu "65816"
.segment "CODE"
.org $F826
map_control_0cf826:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
