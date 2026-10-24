.setcpu "65816"
.segment "CODE"
.org $F3B7
map_control_0cf3b7:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
