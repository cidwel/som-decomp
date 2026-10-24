.setcpu "65816"
.segment "CODE"
.org $6279
map_control_0c6279:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
