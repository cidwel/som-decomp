.setcpu "65816"
.segment "CODE"
.org $A009
map_control_0da009:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
