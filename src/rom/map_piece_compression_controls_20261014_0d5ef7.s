.setcpu "65816"
.segment "CODE"
.org $5EF7
map_control_0d5ef7:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
