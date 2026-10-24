.setcpu "65816"
.segment "CODE"
.org $1C7B
map_control_0e1c7b:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5F ; row-distance/count
