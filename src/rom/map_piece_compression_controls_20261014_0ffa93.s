.setcpu "65816"
.segment "CODE"
.org $FA93
map_control_0ffa93:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
