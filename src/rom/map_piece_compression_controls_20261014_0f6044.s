.setcpu "65816"
.segment "CODE"
.org $6044
map_control_0f6044:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
