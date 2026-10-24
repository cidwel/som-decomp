.setcpu "65816"
.segment "CODE"
.org $1BDE
map_control_0e1bde:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
