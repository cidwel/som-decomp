.setcpu "65816"
.segment "CODE"
.org $74E4
map_control_0d74e4:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
