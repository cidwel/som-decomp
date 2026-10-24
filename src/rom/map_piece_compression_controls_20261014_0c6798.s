.setcpu "65816"
.segment "CODE"
.org $6798
map_control_0c6798:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
