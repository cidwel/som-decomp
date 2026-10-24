.setcpu "65816"
.segment "CODE"
.org $EDAD
map_control_0eedad:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
