.setcpu "65816"
.segment "CODE"
.org $7203
map_control_0f7203:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
