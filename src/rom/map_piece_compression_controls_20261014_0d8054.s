.setcpu "65816"
.segment "CODE"
.org $8054
map_control_0d8054:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
