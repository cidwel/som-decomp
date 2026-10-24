.setcpu "65816"
.segment "CODE"
.org $4194
map_control_0c4194:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
