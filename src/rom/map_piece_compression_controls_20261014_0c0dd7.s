.setcpu "65816"
.segment "CODE"
.org $0DD7
map_control_0c0dd7:
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $F1 ; progressive-copy count
