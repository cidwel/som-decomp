.setcpu "65816"
.segment "CODE"
.org $DEFC
map_control_0edefc:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
