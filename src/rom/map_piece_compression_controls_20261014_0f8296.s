.setcpu "65816"
.segment "CODE"
.org $8296
map_control_0f8296:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
