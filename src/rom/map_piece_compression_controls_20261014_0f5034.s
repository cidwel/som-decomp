.setcpu "65816"
.segment "CODE"
.org $5034
map_control_0f5034:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $71 ; row-distance/count
