.setcpu "65816"
.segment "CODE"
.org $12A5
map_control_0c12a5:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
