.setcpu "65816"
.segment "CODE"
.org $BA30
map_control_0fba30:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
