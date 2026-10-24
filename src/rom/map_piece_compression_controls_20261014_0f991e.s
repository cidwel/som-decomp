.setcpu "65816"
.segment "CODE"
.org $991E
map_control_0f991e:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
