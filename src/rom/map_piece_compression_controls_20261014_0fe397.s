.setcpu "65816"
.segment "CODE"
.org $E397
map_control_0fe397:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
