.setcpu "65816"
.segment "CODE"
.org $7F50
map_control_0f7f50:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
