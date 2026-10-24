.setcpu "65816"
.segment "CODE"
.org $BB86
map_control_0fbb86:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
