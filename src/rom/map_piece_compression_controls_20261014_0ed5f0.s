.setcpu "65816"
.segment "CODE"
.org $D5F0
map_control_0ed5f0:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
