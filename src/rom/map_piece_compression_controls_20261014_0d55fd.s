.setcpu "65816"
.segment "CODE"
.org $55FD
map_control_0d55fd:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
