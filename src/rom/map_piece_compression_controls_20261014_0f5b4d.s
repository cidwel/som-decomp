.setcpu "65816"
.segment "CODE"
.org $5B4D
map_control_0f5b4d:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
