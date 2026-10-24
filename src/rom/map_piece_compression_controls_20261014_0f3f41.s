.setcpu "65816"
.segment "CODE"
.org $3F41
map_control_0f3f41:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7D ; row-distance/count
