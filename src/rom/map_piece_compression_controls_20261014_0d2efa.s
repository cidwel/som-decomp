.setcpu "65816"
.segment "CODE"
.org $2EFA
map_control_0d2efa:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
