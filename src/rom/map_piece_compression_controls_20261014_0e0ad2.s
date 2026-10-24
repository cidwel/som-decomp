.setcpu "65816"
.segment "CODE"
.org $0AD2
map_control_0e0ad2:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
