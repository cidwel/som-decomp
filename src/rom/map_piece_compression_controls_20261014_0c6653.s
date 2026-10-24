.setcpu "65816"
.segment "CODE"
.org $6653
map_control_0c6653:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
