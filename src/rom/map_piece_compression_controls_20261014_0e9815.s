.setcpu "65816"
.segment "CODE"
.org $9815
map_control_0e9815:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
