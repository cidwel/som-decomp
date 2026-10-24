.setcpu "65816"
.segment "CODE"
.org $5222
map_control_0e5222:
    .byte $F2 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
