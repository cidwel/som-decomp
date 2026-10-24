.setcpu "65816"
.segment "CODE"
.org $5C29
map_control_0d5c29:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
