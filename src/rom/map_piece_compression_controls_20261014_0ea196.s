.setcpu "65816"
.segment "CODE"
.org $A196
map_control_0ea196:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
