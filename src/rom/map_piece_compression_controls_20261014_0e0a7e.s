.setcpu "65816"
.segment "CODE"
.org $0A7E
map_control_0e0a7e:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
