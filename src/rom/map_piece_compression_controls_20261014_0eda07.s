.setcpu "65816"
.segment "CODE"
.org $DA07
map_control_0eda07:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
