.setcpu "65816"
.segment "CODE"
.org $F667
map_control_0cf667:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
