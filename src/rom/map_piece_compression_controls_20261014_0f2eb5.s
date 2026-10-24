.setcpu "65816"
.segment "CODE"
.org $2EB5
map_control_0f2eb5:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E2 ; previous-row copy count
