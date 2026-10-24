.setcpu "65816"
.segment "CODE"
.org $668E
map_control_0d668e:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $43 ; distance low bit/count
