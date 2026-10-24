.setcpu "65816"
.segment "CODE"
.org $808D
map_control_0d808d:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
