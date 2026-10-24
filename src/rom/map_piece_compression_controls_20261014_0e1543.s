.setcpu "65816"
.segment "CODE"
.org $1543
map_control_0e1543:
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
