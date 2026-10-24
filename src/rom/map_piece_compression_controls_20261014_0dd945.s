.setcpu "65816"
.segment "CODE"
.org $D945
map_control_0dd945:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
