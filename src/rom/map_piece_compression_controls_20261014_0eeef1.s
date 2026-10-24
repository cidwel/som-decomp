.setcpu "65816"
.segment "CODE"
.org $EEF1
map_control_0eeef1:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
