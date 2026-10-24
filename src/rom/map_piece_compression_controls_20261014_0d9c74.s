.setcpu "65816"
.segment "CODE"
.org $9C74
map_control_0d9c74:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E1 ; previous-row copy count
