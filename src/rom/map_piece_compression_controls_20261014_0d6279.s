.setcpu "65816"
.segment "CODE"
.org $6279
map_control_0d6279:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
