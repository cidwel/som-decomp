.setcpu "65816"
.segment "CODE"
.org $6C37
map_control_0e6c37:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
