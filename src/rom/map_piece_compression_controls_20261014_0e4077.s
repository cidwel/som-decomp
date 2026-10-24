.setcpu "65816"
.segment "CODE"
.org $4077
map_control_0e4077:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
