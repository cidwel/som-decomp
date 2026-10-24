.setcpu "65816"
.segment "CODE"
.org $AF29
map_control_0eaf29:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
