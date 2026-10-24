.setcpu "65816"
.segment "CODE"
.org $CFE5
map_control_0dcfe5:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
