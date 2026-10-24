.setcpu "65816"
.segment "CODE"
.org $E739
map_control_0fe739:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $53 ; distance low bit/count
