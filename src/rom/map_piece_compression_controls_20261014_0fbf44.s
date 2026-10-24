.setcpu "65816"
.segment "CODE"
.org $BF44
map_control_0fbf44:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
