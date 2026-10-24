.setcpu "65816"
.segment "CODE"
.org $C9F3
map_control_0ec9f3:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
