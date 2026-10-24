.setcpu "65816"
.segment "CODE"
.org $E0D1
map_control_0fe0d1:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
