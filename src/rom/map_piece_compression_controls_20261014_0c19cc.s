.setcpu "65816"
.segment "CODE"
.org $19CC
map_control_0c19cc:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7E ; distance low bit/count
