.setcpu "65816"
.segment "CODE"
.org $A767
map_control_0ea767:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
