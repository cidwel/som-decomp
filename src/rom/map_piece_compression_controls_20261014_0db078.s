.setcpu "65816"
.segment "CODE"
.org $B078
map_control_0db078:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
