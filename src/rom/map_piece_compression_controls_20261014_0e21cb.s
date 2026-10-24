.setcpu "65816"
.segment "CODE"
.org $21CB
map_control_0e21cb:
    .byte $F2 ; progressive-copy count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
