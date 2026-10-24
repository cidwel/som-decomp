.setcpu "65816"
.segment "CODE"
.org $3F03
map_control_0d3f03:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
