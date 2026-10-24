.setcpu "65816"
.segment "CODE"
.org $5FA8
map_control_0f5fa8:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E5 ; previous-row copy count
