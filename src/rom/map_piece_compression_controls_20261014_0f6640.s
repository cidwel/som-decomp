.setcpu "65816"
.segment "CODE"
.org $6640
map_control_0f6640:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
