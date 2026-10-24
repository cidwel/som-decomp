.setcpu "65816"
.segment "CODE"
.org $0D1E
map_control_0d0d1e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
