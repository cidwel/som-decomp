.setcpu "65816"
.segment "CODE"
.org $8224
map_control_0f8224:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E1 ; previous-row copy count
