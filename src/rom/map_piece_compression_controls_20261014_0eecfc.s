.setcpu "65816"
.segment "CODE"
.org $ECFC
map_control_0eecfc:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $55 ; row-distance/count
