.setcpu "65816"
.segment "CODE"
.org $ABEF
map_control_0eabef:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
