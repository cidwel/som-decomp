.setcpu "65816"
.segment "CODE"
.org $D65B
map_control_0ed65b:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $77 ; row-distance/count
