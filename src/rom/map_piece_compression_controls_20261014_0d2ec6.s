.setcpu "65816"
.segment "CODE"
.org $2EC6
map_control_0d2ec6:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
