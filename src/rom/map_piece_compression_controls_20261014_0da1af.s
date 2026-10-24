.setcpu "65816"
.segment "CODE"
.org $A1AF
map_control_0da1af:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
