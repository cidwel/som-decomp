.setcpu "65816"
.segment "CODE"
.org $FA53
map_control_0ffa53:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
