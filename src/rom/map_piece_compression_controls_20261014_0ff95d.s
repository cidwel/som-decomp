.setcpu "65816"
.segment "CODE"
.org $F95D
map_control_0ff95d:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
