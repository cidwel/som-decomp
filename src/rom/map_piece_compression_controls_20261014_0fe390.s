.setcpu "65816"
.segment "CODE"
.org $E390
map_control_0fe390:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
