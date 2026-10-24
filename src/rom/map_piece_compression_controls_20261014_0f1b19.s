.setcpu "65816"
.segment "CODE"
.org $1B19
map_control_0f1b19:
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3B ; distance low bit/count
