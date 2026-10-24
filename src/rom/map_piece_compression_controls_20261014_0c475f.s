.setcpu "65816"
.segment "CODE"
.org $475F
map_control_0c475f:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
