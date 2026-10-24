.setcpu "65816"
.segment "CODE"
.org $BA8A
map_control_0fba8a:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
