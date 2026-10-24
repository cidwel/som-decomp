.setcpu "65816"
.segment "CODE"
.org $ABFA
map_control_0dabfa:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
