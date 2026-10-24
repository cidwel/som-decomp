.setcpu "65816"
.segment "CODE"
.org $2239
map_control_0e2239:
    .byte $F2 ; progressive-copy count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
