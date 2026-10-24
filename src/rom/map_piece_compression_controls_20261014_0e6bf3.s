.setcpu "65816"
.segment "CODE"
.org $6BF3
map_control_0e6bf3:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
