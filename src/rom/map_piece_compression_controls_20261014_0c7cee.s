.setcpu "65816"
.segment "CODE"
.org $7CEE
map_control_0c7cee:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
