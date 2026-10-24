.setcpu "65816"
.segment "CODE"
.org $A98B
map_control_0ea98b:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
