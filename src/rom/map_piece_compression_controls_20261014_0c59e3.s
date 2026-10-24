.setcpu "65816"
.segment "CODE"
.org $59E3
map_control_0c59e3:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
