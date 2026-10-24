.setcpu "65816"
.segment "CODE"
.org $90BD
map_control_0c90bd:
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
