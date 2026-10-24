.setcpu "65816"
.segment "CODE"
.org $AB1A
map_control_0eab1a:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
