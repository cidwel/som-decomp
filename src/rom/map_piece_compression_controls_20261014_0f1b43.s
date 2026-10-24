.setcpu "65816"
.segment "CODE"
.org $1B43
map_control_0f1b43:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
