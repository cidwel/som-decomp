.setcpu "65816"
.segment "CODE"
.org $F999
map_control_0ef999:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
