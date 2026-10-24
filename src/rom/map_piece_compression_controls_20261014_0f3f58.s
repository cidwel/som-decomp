.setcpu "65816"
.segment "CODE"
.org $3F58
map_control_0f3f58:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
