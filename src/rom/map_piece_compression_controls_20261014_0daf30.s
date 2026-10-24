.setcpu "65816"
.segment "CODE"
.org $AF30
map_control_0daf30:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
