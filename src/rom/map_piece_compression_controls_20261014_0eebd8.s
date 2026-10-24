.setcpu "65816"
.segment "CODE"
.org $EBD8
map_control_0eebd8:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
