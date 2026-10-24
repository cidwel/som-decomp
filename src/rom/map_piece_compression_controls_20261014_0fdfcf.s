.setcpu "65816"
.segment "CODE"
.org $DFCF
map_control_0fdfcf:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
