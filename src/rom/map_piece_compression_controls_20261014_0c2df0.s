.setcpu "65816"
.segment "CODE"
.org $2DF0
map_control_0c2df0:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
