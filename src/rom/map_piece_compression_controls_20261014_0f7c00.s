.setcpu "65816"
.segment "CODE"
.org $7C00
map_control_0f7c00:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E5 ; previous-row copy count
