.setcpu "65816"
.segment "CODE"
.org $3C12
map_control_0c3c12:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
