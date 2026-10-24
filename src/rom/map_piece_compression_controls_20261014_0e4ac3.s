.setcpu "65816"
.segment "CODE"
.org $4AC3
map_control_0e4ac3:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
