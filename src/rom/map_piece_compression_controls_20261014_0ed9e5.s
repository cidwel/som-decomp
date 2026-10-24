.setcpu "65816"
.segment "CODE"
.org $D9E5
map_control_0ed9e5:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
