.setcpu "65816"
.segment "CODE"
.org $A729
map_control_0ea729:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
