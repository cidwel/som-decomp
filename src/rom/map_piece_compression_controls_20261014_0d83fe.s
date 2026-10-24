.setcpu "65816"
.segment "CODE"
.org $83FE
map_control_0d83fe:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
