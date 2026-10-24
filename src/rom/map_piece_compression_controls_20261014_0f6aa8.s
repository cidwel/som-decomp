.setcpu "65816"
.segment "CODE"
.org $6AA8
map_control_0f6aa8:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
