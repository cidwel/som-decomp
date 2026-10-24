.setcpu "65816"
.segment "CODE"
.org $621B
map_control_0c621b:
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
