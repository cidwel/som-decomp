.setcpu "65816"
.segment "CODE"
.org $CAB1
map_control_0ecab1:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
