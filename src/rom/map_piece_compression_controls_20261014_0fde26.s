.setcpu "65816"
.segment "CODE"
.org $DE26
map_control_0fde26:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
