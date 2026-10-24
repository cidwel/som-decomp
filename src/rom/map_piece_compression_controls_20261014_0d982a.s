.setcpu "65816"
.segment "CODE"
.org $982A
map_control_0d982a:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
