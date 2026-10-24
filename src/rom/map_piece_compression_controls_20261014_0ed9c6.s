.setcpu "65816"
.segment "CODE"
.org $D9C6
map_control_0ed9c6:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
