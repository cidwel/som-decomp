.setcpu "65816"
.segment "CODE"
.org $DDAD
map_control_0eddad:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $5A ; distance low bit/count
