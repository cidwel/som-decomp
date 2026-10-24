.setcpu "65816"
.segment "CODE"
.org $8BD9
map_control_0c8bd9:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
